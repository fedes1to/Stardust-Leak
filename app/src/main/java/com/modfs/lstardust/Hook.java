package com.modfs.lstardust;

import android.content.Context;
import android.os.StrictMode;
import android.util.Log;

import org.lsposed.lsparanoid.Obfuscate;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.net.InetAddress;
import java.net.URL;
import java.net.HttpURLConnection;
import java.nio.channels.Channels;
import java.nio.channels.FileChannel;
import java.nio.channels.ReadableByteChannel;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Objects;
import java.util.Scanner;

import de.robv.android.xposed.IXposedHookLoadPackage;
import de.robv.android.xposed.XC_MethodHook;
import de.robv.android.xposed.XposedBridge;
import de.robv.android.xposed.XposedHelpers;
import de.robv.android.xposed.callbacks.XC_LoadPackage;

@Obfuscate
public class Hook implements IXposedHookLoadPackage  {
    private static Context appContext = null;

    boolean needsDownload = false;
    boolean forceLoad = true;
    String remoteVersion = "";

    public static InputStream resourceStream(String name) {
        return Objects.requireNonNull(Hook.class.getClassLoader()).getResourceAsStream(name);
    }

    @Override
    public void handleLoadPackage(XC_LoadPackage.LoadPackageParam lpparam) throws Throwable {
        if (!lpparam.packageName.equals("com.pixel.gun3d")) //check if the package being loaded is our target
            return;

        // Log.i(TAG, "Entered handleLoadPackage");

        // code here
        XposedHelpers.findAndHookMethod("android.content.ContextWrapper", lpparam.classLoader, "attachBaseContext", Context.class, new XC_MethodHook() {
            @Override
            protected void beforeHookedMethod(MethodHookParam param) throws Throwable {
                appContext = (Context) param.args[0];
            }
        });

        XposedHelpers.findAndHookMethod("java.lang.Runtime", lpparam.classLoader, "load0", Class.class, String.class, new XC_MethodHook() {
            @Override
            protected void beforeHookedMethod(MethodHookParam param) throws Throwable {
                super.beforeHookedMethod(param);
            }

            @Override
            protected void afterHookedMethod(MethodHookParam param) throws Throwable {
                Class<?> fromClass = (Class<?>) param.args[0];
                String libName = (String) param.args[1];
                Log.d("LStardust[java]", "load0: " + libName);
                if (libName != null && libName.endsWith("libmain.so")) { // done so this code runs only once
                    if (appContext == null)
                        return;

                    StrictMode.ThreadPolicy policy = new StrictMode.ThreadPolicy.Builder().permitAll().build();
                    StrictMode.setThreadPolicy(policy);


                    String pathname = (appContext.getCacheDir().toURI() + "libstardust.so").substring("file:".length());
                    String pathnamever = (appContext.getCacheDir().toURI() + "stardustver.txt").substring("file:".length());

                    // code to check version here?
                    try {
                        InetAddress ipAddr = InetAddress.getByName("modfs.dev");
                        needsDownload = ipAddr.equals("");
                    } catch(Exception e) {
                        needsDownload = true;
                    }

                    try {
                        URL url = new URL("https://modfs.dev/version?name=stardust");
                        HttpURLConnection connection = (HttpURLConnection) url.openConnection();
                        connection.setRequestMethod("GET");
                        remoteVersion = new Scanner(connection.getInputStream()).useDelimiter("\\Z").next();
                        connection.disconnect();

                        File versionfile = new File(pathnamever);
                        if (versionfile.exists()) {
                            String content = new Scanner(versionfile).useDelimiter("\\Z").next();
                            String contentnum = content.replaceAll("[^0-9]", "");
                            String responsenum = remoteVersion.replaceAll("[^0-9]", "");
                            int localversion = Integer.parseInt(contentnum);
                            int remoteversion = Integer.parseInt(responsenum);

                            if (localversion != remoteversion)
                                needsDownload = true;

                        } else {
                            needsDownload = true;
                        }

                    } catch (IOException e) {
                        e.printStackTrace();
                        needsDownload = false;
                    }

                    if (!needsDownload) {
                        File soFile = new File(pathname);
                        if (!soFile.exists() || forceLoad) {
                            InputStream soFileStream = resourceStream("lib/arm64-v8a/libstardust.so");
                            byte[] soFileContent = new byte[soFileStream.available()];
                            soFileStream.read(soFileContent);
                            soFile.createNewFile();
                            FileOutputStream out = new FileOutputStream(soFile);
                            out.write(soFileContent);
                        }
                    } else {
                        String fileUrl = "https://modfs.dev/download?menu=stardust?arch=arm64-v8a?version=latest";
                        URL url = new URL(fileUrl);
                        File versionfile = new File(pathnamever);
                        if (versionfile.exists())
                            versionfile.delete();

                        try {
                            FileWriter fileWriter = new FileWriter(pathnamever);
                            BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
                            bufferedWriter.write(remoteVersion);

                            ReadableByteChannel readableByteChannel = Channels.newChannel(url.openStream());
                            FileOutputStream fileOutputStream = new FileOutputStream(pathname);
                            FileChannel fileChannel = fileOutputStream.getChannel();
                            fileChannel.transferFrom(readableByteChannel, 0, Long.MAX_VALUE);
                        } catch (IOException e) {
                            Log.e("LStardust[java]", "Couldn't download file: " + e.getCause());
                        }
                    }
                    Object[] newArgs = new Object[]{fromClass, pathname};
                    XposedBridge.invokeOriginalMethod(param.method, param.thisObject, newArgs);
                }
            }
        });

    }

}

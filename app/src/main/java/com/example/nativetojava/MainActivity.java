package com.example.nativetojava;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.widget.Toast;


public class MainActivity extends Activity {
    private static final String TAG = "MainActivity";
    private String mName = "Java";
    private static int sNumber = 100;

    static {
        System.loadLibrary("NativeToJava");
    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        String msg = "java to native now";
        showMessage(msg);
        callbackFromNative();
    }

    private void showMessage(String message){
        Log.e(TAG, "showMessage()....mName = " + mName + ",sNumber = " + sNumber
                + ",message: " + message);
        Toast.makeText(this,message,Toast.LENGTH_LONG).show();
    }

    private native void callbackFromNative();
}

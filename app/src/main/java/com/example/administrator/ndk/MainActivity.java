package com.example.administrator.ndk;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());

        testInt(12,false,'a',"郭枫",new String[]{"大哥","小哥"},new int[]{10,20},new char[]{'a','b'},new boolean[]{true,false});
    }

    public native String stringFromJNI();

    public native void testInt(int i,boolean flag,char c,String s,String[] strings,int[] ints,char[] chars,boolean[] booleens);
}

/*
 * Copyright 2015 The Go Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style
 * license that can be found in the LICENSE file.
 */

package org.golang.example.bind;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.alibaba.fastjson.JSONArray;

import java.util.ArrayList;
import java.util.List;

import hello.Counter;
import hello.Hello;
import hello.Printer;
import hello.Request;

public class MainActivity extends Activity {

    public static final String TAG = "MainActivity";
    private TextView mTextView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mTextView = (TextView) findViewById(R.id.mytextview);

        // Call Go function.
        Counter counter = Hello.newCounter();
        counter.inc();
        Log.i(TAG, "onCreate: counter value " + counter.getValue());

        // 通过Json传递复杂数据至JNI层
        JSONArray cmds = new JSONArray();
        cmds.add("echo");
        cmds.add("hello");
        String command = cmds.toJSONString();
        Request request = Hello.newRequest(command, false, 0);
        String json = request.jsonEncode();
        Log.i(TAG, "onCreate: json: " + json);

        mTextView.setText("counter = " + counter + json); // 11

        // Passing target language objects to Go
        Printer printer = new Printer() {
            @Override
            public void print(String s) {
                Log.w(TAG, "I print: " + s);
            }
        };
        Hello.printHello(printer); // 将printer传递至Golang
    }
}

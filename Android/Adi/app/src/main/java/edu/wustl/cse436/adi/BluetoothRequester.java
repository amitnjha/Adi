package edu.wustl.cse436.adi;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.Intent;

import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Set;
import java.util.UUID;
import java.util.concurrent.BlockingDeque;

/**
 * Created by AMITJHA on 7/24/2015.
 */
public class BluetoothRequester {

    String piUUID = "DC:A6:32:1F:2B:B0";
    PrintWriter writer ;//= new PrintWriter(bout);
    BluetoothSocket socket ;

    public BluetoothRequester(){
        BluetoothAdapter adapter = BluetoothAdapter.getDefaultAdapter();

        if(adapter == null){
            //bluetooth is not supported
            return;
        }

        //if (!adapter.isEnabled()) {
        //    Intent enableBtIntent = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
        //    startActivityForResult(enableBtIntent, BluetoothAdapter.REQUEST_ENABLE_BT);
       // }

        Set<BluetoothDevice> bondedDevices = adapter.getBondedDevices();

        OutputStream bout;
        for (BluetoothDevice device : bondedDevices){
            if (device.getAddress() .equals(piUUID)){
                try {
                    socket = device.createInsecureRfcommSocketToServiceRecord(UUID.fromString("1e0ca4ea-299d-4335-93eb-27fcfe7fa848"));
                    socket.connect();
                    bout = socket.getOutputStream();
                    writer = new PrintWriter(bout);
                    writer.println("test 2");
                    writer.flush();
                } catch (IOException e) {
                    e.printStackTrace();
                }

            }
        }

    }

    //try reconnecting if connection was closed due to some reason.
    public boolean reconnect(){
        BluetoothAdapter adapter = BluetoothAdapter.getDefaultAdapter();

        if(adapter == null){
            //bluetooth is not supported
            return false;
        }

        //if (!adapter.isEnabled()) {
        //    Intent enableBtIntent = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
        //    startActivityForResult(enableBtIntent, BluetoothAdapter.REQUEST_ENABLE_BT);
        // }

        Set<BluetoothDevice> bondedDevices = adapter.getBondedDevices();

        OutputStream bout;
        for (BluetoothDevice device : bondedDevices){
            if (device.getAddress() .equals(piUUID)){
                try {
                    socket = device.createInsecureRfcommSocketToServiceRecord(UUID.fromString("1e0ca4ea-299d-4335-93eb-27fcfe7fa848"));
                    socket.connect();
                    bout = socket.getOutputStream();
                    writer = new PrintWriter(bout);
                    writer.println("test 2");
                    writer.flush();
                } catch (IOException e) {
                    e.printStackTrace();
                }

            }
        }
        return  true;
    }
    public boolean sendRequest(String action, String count){
        if(socket!=null && socket.isConnected() && writer!=null ){

            writer.println(action + " " + count);
            writer.flush();
            return true;
        }else{
            // alert that connectivity is not ready
            return  false;

        }
        
    }
}

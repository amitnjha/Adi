package edu.wustl.cse436.adi;

import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.TextView;


public class BluetoothActivity extends ActionBarActivity {

    class inner implements View.OnClickListener{
        @Override
        public void onClick(View v) {
                String desc = String.valueOf(v.getContentDescription());
                //((TextView)findViewById(R.id.textView)).setText(desc);
                String count ="1";
                if(v.getId() == R.id.forwardButton){
                    count = String.valueOf(((Button)findViewById(R.id.forwardStepper)).getText());
                }else if(v.getId() == R.id.reverseButton){
                    count = String.valueOf(((Button)findViewById(R.id.reverseStepper)).getText());
                }else if(v.getId() == R.id.leftButton){
                    count = String.valueOf(((Button)findViewById(R.id.leftStepper)).getText());
                }else if(v.getId() == R.id.rightButton){
                    count = String.valueOf(((Button)findViewById(R.id.rightStepper)).getText());
                }
            //String message = desc + "," + count;
            //send to pi via bluetooth
            boolean reqSent = requester.sendRequest(desc,count);
            if(!reqSent){
                //if false -- display that request could not be sent.

            }
            //((TextView)findViewById(R.id.textView)).setText(desc + "," + count);
        }
    }

    BluetoothRequester requester;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_bluetooth);
        inner listener = new inner();
        StepperClickListener stepperClickListener = new StepperClickListener();
        ((ImageButton)findViewById(R.id.forwardButton)).setOnClickListener(listener);
        ((ImageButton)findViewById(R.id.leftButton)).setOnClickListener(listener);
        ((ImageButton)findViewById(R.id.rightButton)).setOnClickListener(listener);
        ((ImageButton)findViewById(R.id.reverseButton)).setOnClickListener(listener);
        ((ImageButton)findViewById(R.id.haltButton)).setOnClickListener(listener);

        findViewById(R.id.forwardStepper).setOnClickListener(stepperClickListener);
        findViewById(R.id.leftStepper).setOnClickListener(stepperClickListener);
        findViewById(R.id.rightStepper).setOnClickListener(stepperClickListener);
        findViewById(R.id.reverseStepper).setOnClickListener(stepperClickListener);
        //findViewById(R.id.leftStepper).setOnClickListener(stepperClickListener);
        requester = new BluetoothRequester();
        ((TextView)findViewById(R.id.connectionStatus)).setText("Connection Status : " + requester.socket.isConnected());
    }


    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_bluetooth, menu);
        return true;
    }
    public void leftButtonClicked(View v){
        System.out.println("aaya re");
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}

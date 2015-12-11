package edu.wustl.cse436.adi;

import android.view.View;
import android.widget.Button;

import java.util.ArrayList;
import java.util.Enumeration;
import java.util.List;

/**
 * Created by AMITJHA on 7/24/2015.
 */
public class StepperClickListener implements View.OnClickListener {

    //Enumeration<int> values = [1,2,3]
    enum StepperValue {
        ONE,
        TWO,
        THREE,
        FOUR,
        FIVE
    }

    List<String> stepperValList = new ArrayList<String>();
    public StepperClickListener(){
        super();
        stepperValList = new ArrayList<String>();
        stepperValList.add("1");
        stepperValList.add("2");
        stepperValList.add("3");
        stepperValList.add("4");
        stepperValList.add("5");
        stepperValList.add("6");
    }

    @Override
    public void onClick(View v) {
        Button btn = (Button)v;
        int currentIdx = stepperValList.indexOf((btn.getText()));
        if(currentIdx == stepperValList.size()-1){
            //reset to 1
            btn.setText(stepperValList.get(0));
        }else{
            //set to next val
            btn.setText(stepperValList.get(currentIdx+1));
        }
    }

}

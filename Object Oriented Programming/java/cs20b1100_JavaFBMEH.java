import java.awt.*;
import java.awt.event.*;
import java.applet.*;

public class cs20b1100_JavaFBMEH extends Applet implements ActionListener,KeyListener
{
    Button b0,b1,b2,b3,b4,b5,b6,b7,b8,b9,bavg,badd,baddt,bclear,bdec;
    TextField tf,t1,t2,t3,t4,t5,t6,tOp;
    String number1="";
    String number2="";
    String Op="";

    public void init()
    {
        setLayout(null); 
        tf=new TextField();  
        tf.setBounds(50,40,240,60);  

        setLayout(null);
        b0 = new Button("0");
        b1 = new Button("1");
        b2 = new Button("2");
        b3 = new Button("3");
        b4 = new Button("4");
        b5 = new Button("5");
        b6 = new Button("6");
        b7 = new Button("7");
        b8 = new Button("8");
        b9 = new Button("9");
        bavg = new Button(" Average Camps "); 
        badd = new Button(" Total Emergency Services "); 
        baddt = new Button(" Total Hospitals "); 

        bdec = new Button(".");
        
        bclear = new Button("C"); 
        
        b1.setBounds(50,120,60,50);
        b2.setBounds(110,120,60,50);
        b3.setBounds(170,120,60,50);
        b4.setBounds(50,170,60,50);
        b5.setBounds(110,170,60,50);
        b6.setBounds(170,170,60,50);
        b7.setBounds(50,220,60,50);
        b8.setBounds(110,220,60,50);
        b9.setBounds(170,220,60,50);
        b0.setBounds(50,270,60,50);
        bavg.setBounds(230,270,200,50);
        badd.setBounds(230,220,200,50);
        baddt.setBounds(230,170,200,50);
        bdec.setBounds(110,270,60,50);
        bclear.setBounds(50,320,240,60);
  
        add(b0); 
        add(b1); 
        add(b2); 
        add(b3); 
        add(b4); 
        add(b5); 
        add(b6); 
        add(b7); 
        add(b8); 
        add(b9); 
        add(bavg); 
        add(badd); 
        add(baddt);
        
        add(bdec);
        add(bclear);
        
        add(tf);  

        b0.addActionListener(this);  
        b1.addActionListener(this);  
        b2.addActionListener(this); 
        b3.addActionListener(this);  
        b4.addActionListener(this);  
        b5.addActionListener(this); 
        b6.addActionListener(this);  
        b7.addActionListener(this);  
        b8.addActionListener(this); 
        b9.addActionListener(this); 
        bavg.addActionListener(this);
        badd.addActionListener(this); 
        baddt.addActionListener(this); 
        
        bdec.addActionListener(this);
       
        bclear.addActionListener(this);  
       

        b0.addKeyListener(this);  
        b1.addKeyListener(this);  
        b2.addKeyListener(this); 
        b3.addKeyListener(this);  
        b4.addKeyListener(this);  
        b5.addKeyListener(this); 
        b6.addKeyListener(this);  
        b7.addKeyListener(this);  
        b8.addKeyListener(this); 
        b9.addKeyListener(this);  
        bavg.addKeyListener(this); 
        badd.addKeyListener(this); 
        baddt.addKeyListener(this); 
         
        bdec.addKeyListener(this);
       
        bclear.addKeyListener(this); 
        tf.addKeyListener(this);  
    }

    public void actionPerformed(ActionEvent e)
    {  
        String b = e.getActionCommand();
        char c = b.charAt(0);

        if(c>='0' && c<='9'|| c=='.') 
	    { 
	        if (!Op.equals("")) 
            {
                number2 = number2 + b;
            }
		    else
            {
                number1 = number1 + b; 
            }
		   
	        tf.setText(number1+Op+number2); 
	    } 
        else if(c=='C') 
	    { 
	        number1 = Op = number2 = ""; 
	        tf.setText(""); 
	    }
	    else if (c == ) 
	    { 
	        if(!number1.equals("") && !number2.equals(""))
	        {
		        double temp;
		        double num1 = Double.parseDouble(number1);
		        double num2 = Double.parseDouble(number2);
		        if(num2 == 0 && Op.equals("/"))
		        {
		            tf.setText(number1+Op+number2+" = Zero Division Error");
		            number1 = Op = number2 = "";
		        }
                else
                {
                    if (Op.equals("+"))
                    {
                        temp = num1 + num2; 
                    }  
		            else if (Op.equals("-")) 
                    {
		                temp = num1 - num2; 
                    }
                    else if (Op.equals("/")) 
	  	            {
                        temp = num1/num2; 
                    }
                    else
                    {
		                temp = num1*num2; 
                    }

                    tf.setText(number1+Op+number2+" = "+temp); 
		            number1 = Double.toString(temp);
		            Op = number2 = ""; 
                }
            }
            else
	        {
		        number1 = Op = number2 = ""; 
		        tf.setText("");
	        }
        }
        else 
	    { 
            if (Op.equals("") || number2.equals("")) 
	            Op = b; 
            else 
            { 
	            double temp;
	            double num1=Double.parseDouble(number1);
	            double num2=Double.parseDouble(number2);
	            if(num2==0 && Op.equals("/"))
	            {
	                tf.setText(number1+Op+number2+" = Zero Division Error");
	                number1 = Op = number2 = "";
	            }
	            else
	            {
	              if (Op.equals("+")) 
                  {
	                temp = num1 + num2;
                  } 
	              else if (Op.equals("-"))
                  { 
	                temp = num1 - num2; 
                  }
	              else if (Op.equals("/")) 
                  {
  	                temp = num1/num2; 
                  }
                  else
                  {
	                temp = num1*num2; 
                  }

	              number1 = Double.toString(temp); 
	              Op = b; 
	              number2 = ""; 
	            }
            }
	        tf.setText(number1+Op+number2);
        }    
    }   
}

/* 
<applet code="cs20b1100_JavaFBMEH.class" width="1080" height="1920"> 
</applet> 
*/  
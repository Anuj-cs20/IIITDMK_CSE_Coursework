import java.awt.*;  
import java.awt.event.*;  
import java.applet.*;  
public class time extends Applet implements ActionListener  
{  
    // Button b0,b1,b2,b3,b4,b5,b6,b7,b8,b9,bdec,bclear;
    // b0 = new Button("0");
    // b1 = new Button("1");
    // b2 = new Button("2");
    // b3 = new Button("3");
    // b4 = new Button("4");
    // b5 = new Button("5");
    // b6 = new Button("6");
    // b7 = new Button("7");
    // b8 = new Button("8");
    // b9 = new Button("9");
    // bdec = new Button(".");
    // bclear = new Button("C"); 

    TextField t1 = new TextField(130);  
    TextField t2 = new TextField(130);  
    TextField t3 = new TextField(130);
    TextField t4 = new TextField(130);  
    TextField t5 = new TextField(130);  
    TextField t6 = new TextField(130); 
    TextField tOp = new TextField(130);   
    
    Label l1 = new Label("1st Number: ");  
    Label l2 = new Label("2nd Number: ");  
    Label l3 = new Label("3rd Number: ");  
    Label l4 = new Label("4th Number: ");  
    Label l5 = new Label("5th Number: ");  
    Label l6 = new Label("6th Number: "); 

    Label Op = new Label("Output: "); 

    Button a = new Button(" Average Camps ");  
    Button b = new Button(" Total Emergency Services ");  
    Button c = new Button(" Total Hospitals "); 
    Button d = new Button(" Clear ");

    public void init()  
    {   
        // b1.setBounds(50,120,60,50);
        // b2.setBounds(110,120,60,50);
        // b3.setBounds(170,120,60,50);
        // b4.setBounds(50,170,60,50);
        // b5.setBounds(110,170,60,50);
        // b6.setBounds(170,170,60,50);
        // b7.setBounds(50,220,60,50);
        // b8.setBounds(110,220,60,50);
        // b9.setBounds(170,220,60,50);
        // b0.setBounds(50,270,60,50);
        // bdec.setBounds(110,270,60,50);
        // bclear.setBounds(50,320,240,60);


        add(l1);  
        add(t1);  
        add(l2);  
        add(t2);  
        add(l3);  
        add(t3); 
        add(l4);  
        add(t4);  
        add(l5);  
        add(t5);  
        add(l6);  
        add(t6);
        add(Op);
        add(tOp);
        add(a);
        add(b);
        add(c); 
        add(d);

        // add(b0); 
        // add(b1); 
        // add(b2); 
        // add(b3); 
        // add(b4); 
        // add(b5); 
        // add(b6); 
        // add(b7); 
        // add(b8); 
        // add(b9);
        // add(bdec);
        // add(bclear); 
 
        // b0.addActionListener(this);  
        // b1.addActionListener(this);  
        // b2.addActionListener(this); 
        // b3.addActionListener(this);  
        // b4.addActionListener(this);  
        // b5.addActionListener(this); 
        // b6.addActionListener(this);  
        // b7.addActionListener(this);  
        // b8.addActionListener(this); 
        // b9.addActionListener(this); 
        // bdec.addActionListener(this);
        // bclear.addActionListener(this); 

        a.addActionListener(this);  
        b.addActionListener(this);  
        c.addActionListener(this);
        d.addActionListener(this);  
    }  

    public void actionPerformed(ActionEvent e)  
    {  
        if (e.getSource() == b || e.getSource() == c )  
        {  
            int n1 = Integer.parseInt(t1.getText());  
            int n2 = Integer.parseInt(t2.getText()); 
            int n3 = Integer.parseInt(t3.getText());  
            int n4 = Integer.parseInt(t4.getText());
            int n5 = Integer.parseInt(t5.getText());  
            int n6 = Integer.parseInt(t6.getText()); 

            tOp.setText(" " + (n1 + n2 + n3 + n4 + n5 + n6));  
        }  

        if (e.getSource() == a )  
        {  
            int n1 = Integer.parseInt(t1.getText());  
            int n2 = Integer.parseInt(t2.getText()); 
            int n3 = Integer.parseInt(t3.getText());  
            int n4 = Integer.parseInt(t4.getText());
            int n5 = Integer.parseInt(t5.getText());  
            int n6 = Integer.parseInt(t6.getText()); 
              
            tOp.setText(" " + (n1 + n2 + n3 + n4 + n5 + n6)/6 );  
        }  

        if (e.getSource() == d )  
        {      
            t1.setText("");
            t2.setText("");
            t3.setText("");
            t4.setText("");
            t5.setText("");
            t6.setText("");
            tOp.setText("");  
        }  


        // String b = e.getActionCommand();
        // char c = b.charAt(0);

        // if(c>='0' && c<='9'|| c=='.') 
	    // {  
	    //     t1.setText(c); 
	    // } 
        // else if(c=='C') 
	    // {  
	    //     t1.setText("");
        //      t2.setText("");
        //       t3.setText("");
        //      t4.setText("");
        //      t5.setText("");
        //      t6.setText("");
        //       tOp.setText("");     
	    // }
    }  
}  

/* 
<applet code="time.class" width="1080" height="1920"> 
</applet> 
*/  
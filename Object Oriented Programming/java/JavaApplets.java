import java.applet.Applet;
import java.awt.Graphics;
import java.awt.Font;
import java.awt.Color;


public class cs20b1100_JavaApplets extends Applet
{
    public void paint(Graphics g){

        g.setColor(new Color(255,0,0));
        g.drawOval(824,0,200,100);

        g.setColor(new Color(0,255,0));
        g.fillOval(874,25,100,50);

        g.setColor(new Color(255,255,0));
        g.fillRect(0,620,100,100);

        g.setColor(new Color(0,0,255));
        g.drawRect(25,645,50,50);
        
        g.setColor(new Color(0,255,255));
        g.fillOval(362,210,300,300);

        g.setColor(new Color(255,0,255));
        g.setFont(new Font("Verdana", Font.PLAIN, 32));
        g.drawString("Applet",464,350);

        g.setFont(new Font("Verdana", Font.BOLD, 32));
        g.setColor(new Color(255,255,255));
        g.drawString("Program",442,380);
        
    
    }
}
/*
<applet code="JavaApplets.class" width="1024" height="720"> 
</applet> 
*/
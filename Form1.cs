using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.IO.Ports;


namespace ComputerToArduino
{
    public partial class Form1 : Form

    {
        bool isConnected = false;
        String[] ports;
        SerialPort port;

        public Form1()
        {
            InitializeComponent();
            disableControls();
            getAvailableComPorts();

            foreach (string port in ports)
            {
                comboBox1.Items.Add(port);
                Console.WriteLine(port);
                if (ports[0] != null)
                {
                    comboBox1.SelectedItem = ports[0];
                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (!isConnected)
            {
                connectToArduino();
            } else
            {
                disconnectFromArduino();
            }
        }

        void getAvailableComPorts()
        {
            ports = SerialPort.GetPortNames();
        }

        private void connectToArduino()
        {
            isConnected = true;
            string selectedPort = comboBox1.GetItemText(comboBox1.SelectedItem);
            port = new SerialPort(selectedPort, 9600, Parity.None, 8, StopBits.One);
            port.Open();
            port.Write("#STAR\n");
            button1.Text = "Disconnect";
            enableControls();
        }

        private void Led1CheckboxClicked(object sender, EventArgs e)

        {
            if(isConnected)
            {
                if(checkBox1.Checked)
                {
                    port.Write("#LED1ON\n");
                }else
                {
                    port.Write("#LED1OF\n");
                }
            }
        }

        private void Led2CheckboxClicked(object sender, EventArgs e)

        {
            if (isConnected)
            {
                if (checkBox2.Checked)
                {
                    port.Write("#LED2ON\n");
                }
                else
                {
                    port.Write("#LED2OF\n");
                }
            }
        }

        private void Led3CheckboxClicked(object sender, EventArgs e)

        {
            if (isConnected)
            {
                if (checkBox3.Checked)
                {
                    port.Write("#LED3ON\n");
                }
                else
                {
                    port.Write("#LED3OF\n");
                }
            }
        }

        private void Led4CheckboxClicked(object sender, EventArgs e)
        {
            if (isConnected)
            {
                if (checkBox4.Checked)
                {
                    port.Write("#LED4ON\n");
                }
                else
                {
                    port.Write("#LED4OF\n");
                }
            }
        }

        private void Led5CheckboxClicked(object sender, EventArgs e)
        {
            if (isConnected)
            {
                if (checkBox5.Checked)
                {
                    port.Write("#LED5ON\n");
                }
                else
                {
                    port.Write("#LED5OF\n");
                }
            }
        }

        private void Led6CheckboxClicked(object sender, EventArgs e)
        {
            if (isConnected)
            {
                if (checkBox6.Checked)
                {
                    port.Write("#LED6ON\n");
                }
                else
                {
                    port.Write("#LED6OF\n");
                }
            }
        }

        private void Led7CheckboxClicked(object sender, EventArgs e)
        {
            if (isConnected)
            {
                if (checkBox7.Checked)
                {
                    port.Write("#LED7ON\n");
                }
                else
                {
                    port.Write("#LED7OF\n");
                }
            }
        }

        private void Led8CheckboxClicked(object sender, EventArgs e)
        {
            if (isConnected)
            {
                if (checkBox8.Checked)
                {
                    port.Write("#LED8ON\n");
                }
                else
                {
                    port.Write("#LED8OF\n");
                }
            }
        }

        private void disconnectFromArduino()
        {
            isConnected = false;
            port.Write("#STOP\n");
            port.Close();
            button1.Text = "Connect";
            disableControls();
            resetDefaults();
        }

       // private void button2_Click(object sender, EventArgs e)
       // {
         //   if (isConnected)
          //  {
          //      port.Write("#TEXT" + textBox1.Text + "#\n");
          //  }
      //  }

        private void enableControls()
        {
            checkBox1.Enabled = true;
            checkBox2.Enabled = true;
            checkBox3.Enabled = true;
            checkBox4.Enabled = true;
            checkBox5.Enabled = true;
            checkBox6.Enabled = true;
            checkBox7.Enabled = true;
            checkBox8.Enabled = true;
            //button2.Enabled = true;
            //textBox1.Enabled = true;
            groupBox1.Enabled = true;
            //groupBox3.Enabled = true;

        }

        private void disableControls()
        {
            checkBox1.Enabled = false;
            checkBox2.Enabled = false;
            checkBox3.Enabled = false;
            checkBox4.Enabled = false;
            checkBox5.Enabled = false;
            checkBox6.Enabled = false;
            checkBox7.Enabled = false;
            checkBox8.Enabled = false;
            //button2.Enabled = false;
            //textBox1.Enabled = false;
            groupBox1.Enabled = false;
            //groupBox3.Enabled = false;
        }

        private void resetDefaults()
        {
            checkBox1.Checked = false;
            checkBox2.Checked = false;
            checkBox3.Checked = false;
            checkBox4.Checked = false;
            checkBox5.Checked = false;
            checkBox6.Checked = false;
            checkBox7.Checked = false;
            checkBox8.Checked = false;
            //textBox1.Text = "";
            
        }


        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            AboutBox1 box = new AboutBox1();
            box.ShowDialog();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start("https://www.instructables.com/member/vandenbrande/instructables/");
        }

        private void button3_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start("https://www.youtube.com/channel/UCzk_SWD_SASF8UE2FPk9LOA");
        }

        private void button4_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start("https://www.facebook.com/ArduinoProjects101/");
        }

        
    }
}

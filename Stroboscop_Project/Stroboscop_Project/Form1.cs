using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;


namespace Stroboscop_Project
{
    public partial class Form1 : Form
    {

        int db, dl, dt, dr;

        bool updated = false;
        void thr()
        {
            serialPort1.PortName = "COM3";
            serialPort1.BaudRate = 9600;
            serialPort1.Open();


            bool gate = false;

            int k = 0;

            while (true)
            {
                string s = serialPort1.ReadLine();
                if(s != "")
                {
                    listBox1.Invoke(new Action(() => listBox1.Items.Add(s)));
                    if (s == "o")
                    {
                        gate = true;
                    }
                    if (s == "c")
                    {
                        gate = false;
                    }

                    if (gate)
                    {
                        updated = false;
                        try
                        {
                            int n = int.Parse(s);
                            if (k == 0)
                            {
                                db = n;
                            }
                            else
                            {
                                if (k == 1)
                                {
                                    dl = n;
                                }
                                else
                                {
                                    if (k == 2)
                                    {
                                        dt = n;
                                    }
                                    else
                                    {
                                        if (k == 3)
                                        {
                                            dr = n;
                                        }
                                    }
                                }
                            }
                            k++;
                        }
                        catch (Exception)
                        {
                        }
                    }
                    else
                    {
                        updated = true;
                    }
                }
            }
        }

        Thread tread;

        public Form1()
        {
            InitializeComponent();
            tread = new Thread(thr);
            tread.Start();
            timer1.Interval = 200;
            timer1.Start();
        }

        bool gate = false;

        private void timer1_Tick(object sender, EventArgs e)
        {
            label2.Text = db.ToString();
            label3.Text = dl.ToString();
            label4.Text = dt.ToString();
            label5.Text = dr.ToString();
        }

        string[] ser = new string[9];

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            tread.Abort();
        }

        private void btLaunch_Click(object sender, EventArgs e)
        {
        }
    }
}

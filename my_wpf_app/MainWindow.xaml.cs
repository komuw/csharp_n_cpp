using System;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Globalization;
using System.Threading;
using System.IO;

namespace my_wpf_app {

  /// <summary>
  /// Interaction logic for MainWindow.xaml
  /// </summary>
  public partial class MainWindow : Window {
    // This is the code-behind.
    public MainWindow() {
      InitializeComponent();
      var p = new Person();
      this.DataContext = p;
    }

    private class Person {
      public Person() {
        Age = 39;
      }
      public int Age { get; set; }
    }

    private void MyBtnId(object sender, RoutedEventArgs e) {
      myTxtBlk.Text = "Awe btn clicked";
      // e.Handled = true;  // Stops event bubbling.

      var msg = $@"
      MyBtnId: was clicked
      sender={sender}
      event={e}\n";
      File.AppendAllText("event_log.txt", msg);
    }

    private void Hyperlink_OnRequestNavigate(object sender, RequestNavigateEventArgs e) {
      e.Handled = true;
      var msg = $@"
      Hyperlink_OnRequestNavigate: was clicked
      sender={sender}
      event={e}\n";
      File.AppendAllText("event_log.txt", msg);
    }


    private void PopupButton_OpenPopup(object sender, RoutedEventArgs e) {
      // The method name must match the event handler name in the XAML file.
      MyPopup.IsOpen = true;
      // Set keyboard focus to the Hyperlink
      MyCoolHyperlink.Focus();

      var msg = $@"
      Hyperlink_OnRequestNavigate: was clicked
      sender={sender}
      event={e}\n";
      File.AppendAllText("event_log.txt", msg);
    }

    [STAThread]
    public static void Main() {
      Thread.CurrentThread.CurrentUICulture = new CultureInfo("fr");
      var app = new Application();
      var window = new MainWindow();
      app.Run(window);
    }
  }
}

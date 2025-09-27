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

namespace my_wpf_app;

/// <summary>
/// Interaction logic for MainWindow.xaml
/// </summary>
public partial class MainWindow : Window {
  // This is the code-behind.
  public MainWindow() {
    InitializeComponent();
  }

  [STAThread]
  public static void Main() {
    var app = new Application();
    var window = new MainWindow();
    app.Run(window);
  }
}


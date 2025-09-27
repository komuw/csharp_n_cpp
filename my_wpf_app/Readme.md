## sample wpf app.

https://www.tutorialspoint.com/wpf/index.htm

`rm *.sln;dotnet format .;dotnet run .`

- If you have an App.xaml file and an App.xaml.cs file that defines a 
```c#
public partial class App : Application {}
```
then the c# build system will automatically generate the entry point. Hint hence the partial class.   
- However you can keep just one xaml/cs file so long as you include
```c#
 [STAThread]
    public static void Main(){
     var app = new Application();   
    }
```
- In the xaml `x:Class="my_wpf_app.MainWindow"` maps to the `.cs` class that implements the `code-behind`. The code behind contains the logic and event handlers for the UI elements defined in the XAML.    
- You can nest xaml elements;
```xaml
<StackPanel> 
  <Button x:Name="button" Content="Click Me"/> 
</StackPanel>
```


- TODO: resx files.
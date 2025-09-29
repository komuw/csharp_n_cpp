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
- CLR properties are normal `c#` properties with `{get; set;}`. Dependency properties are special in WPF. They support data binding, animation, styling, default values, etc.
  CLR; common language runtime.        
  https://www.tutorialspoint.com/wpf/wpf_dependency_properties.htm     
  eg; `<Trigger Property="IsMouseOver" Value="True">`.  `IsMouseOver` is a dependency property.   
  `x:Type` has similar functionality like `typeof()` in C#
  You can use `DependencyProperty` in c# code to create custom dependency properties.   
  You use dependency properties over clr props if
    (a) If you want to set the style
    (b) If you want data binding
    (c) If you want to set with a resource (a static or a dynamic resource)
    (d) If you want to support animation
```xaml
<Button  Height = "40" Width = "175" Margin = "10" Content = "Dependency Property"> 
  <Button.Style> 
    <Style TargetType = "{x:Type Button}"> 
        <Style.Triggers> 
            <Trigger Property = "IsMouseOver" Value = "True"> 
              <Setter Property = "Foreground" Value = "Red" /> 
          </Trigger>
            </Style.Triggers>
    </Style> 
  </Button.Style> 
</Button>
```
  
- Integrate localization via `resx` files.
  (a) Add `.resx` files to `/Resources/` directory, update `.csproj` file to include `Aigamo.ResXGenerator` which will use the `resx` files to generate `c#` files.      
  (b) The `.haml.cs` code-behind file does not need to be updated except for calling `CultureInfo("fr")` to change the language. 
  `dotnet clean;dotnet build;dotnet run .`  
       
- Event handling. https://www.tutorialspoint.com/wpf/wpf_routed_events.htm 
  You can add events. Look at how `MyBtnId` & `myTxtBlk` are used in `.xaml` and `.cs` file. 
  You can register custom routed events via `RegisterRoutedEvent`   

- You can add a popup that when clicked will reveal others things inside(eg, it has a hyperlink inside). Note it has a PlacementTarget that is the element that will reveal the popup when clicked. In out case it is a button we've named `PopupButton`. That button has one event handler `PopupButton_OpenPopup` that is activated either when button is clicked or someone navigates into it(eg, via keyboard tab key). That event handler also needs to be added to the code-behind and should set `IsOpen` boolean. Note that the hypelink also has an event handler that needs to be added to code-behind(`Hyperlink_OnRequestNavigate`). It should ideally handle the link been clicked and open it up or log it, etc.
```xaml
<Popup x:Name="MyPopup" PlacementTarget="{Binding ElementName=PopupButton}">
<Button x:Name="PopupButton" Content="Show Popup" Click="PopupButton_OpenPopup" GotFocus="PopupButton_OpenPopup"/>
```
```c#
private void PopupButton_OpenPopup(object sender, RoutedEventArgs e) {
  MyPopup.IsOpen = true;
}
```
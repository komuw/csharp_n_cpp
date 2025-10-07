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
  There are 3 types of events: 
    (a) Direct    - raised by an element in which the event originated, eg `MouseEnter`
    (b) Bubbling  - begins with an element then travels up the tree to the topmost element.
    (c) Tunnel    - Event handlers on the root element are invoked then event travels down to all children until it reaches the element in which the event originated.      
  Events are often implemented as a tunneling/bubbling pair. So, you'll have a `previewMouseDown` and then a `MouseDown` event.


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
- To make the hyperlink navigable using keyboard we have two options;
  (a) Implement in code-behind. Add an `x:Name="MyCoolHyperlink"` to the hyperlink then call `MyCoolHyperlink.Focus();` in the code-behind.      
      Commit [810c7d3](https://github.com/komuw/csharp_stuff/commit/810c7d311c1856d25a7c45913ea5309437b719ca) implements that approach. However once focussed, u cant tab away to another element.
  (b) Use a button
```xaml
<Button Content="{Binding SomeClass.Header}"
Command="{Binding SomeClass.Launch}"
Focusable="True"
Style="{StaticResource HyperlinkButtonStyle}" 
Background="Transparent"
BorderThickness="0"
Padding="0"
Foreground="Blue"
Cursor="Hand" />
```

- Controls(UI elements): https://www.tutorialspoint.com/wpf/wpf_controls.htm       
  They are found in `System.Windows.Controls` and can be implemented in `xaml`.      
  eg; Window, Button, Textblock, Popup, Calendar, GridView, ToolTip 

- Layout: https://www.tutorialspoint.com/wpf/wpf_layouts.htm   
  Used to arrange a group of GUI elements in your application.       
  Some layout panels are; `Grid`, `Canvas`, `Dock`, `StackPanel`
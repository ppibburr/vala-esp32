namespace ESP32 {
[CCode (cheader_filename="esp_system.h,driver/gpio.h")]
namespace GPIO {
  [CCode (cname="gpio_set_level")]
  public void digital_write(int pin, int lvl);

  [CCode (cname="gpio_get_level")]
  public int digital_read(int pin);
  
  [CCode (cname="gpio_set_direction")]
  public void set_direction(int pin, int mode);  

  [CCode (cname="gpio_pad_select_gpio")]
  public void pad_select(int pin); 
}

[CCode (cheader_filename="freertos/FreeRTOS.h,freertos/task.h")]
namespace Task {
  [CCode (cname="vTaskDelay")]
  public void delay(int delay);
  
  [CCode (cname="taskYIELD")]
  public void @yield();
  
  [CCode (has_target=false)]
  public delegate void t_func();
  
  [CCode (simple_generics = true,cname="xTaskCreate", has_target=false)]
  public void create<T1, T,T2>(T1 func, string name, int depth,T? data, int priority, T2? handle);  
}

[CCode (cheader_filename="esp_log.h")]
namespace LOG {
	[CCode (cname="ESP_LOGE")]
	public void e(string tag, string msg);

	[CCode (cname="ESP_LOGW")]
	public void w(string tag, string msg);
	
	[CCode (cname="ESP_LOGD")]
	public void d(string tag, string msg);
	
	[CCode (cname="ESP_LOGI")]
	public void i(string tag, string msg);		

	[CCode (cname="ESP_LOGV")]
	public void v(string tag, string msg);	
}
}


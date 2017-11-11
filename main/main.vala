using ESP32;

[Compact]
public class BlinkTask {
  public void start() {
    LOG.v("Blink", "Started");
    Task.create<Task.t_func, void, void>(run, "Blink", 1024, null, 5, null);
  }

  public static void run() {
    GPIO.pad_select(23);
    GPIO.set_direction(23, 2);
    while (true) {
      for (int lvl = 0; lvl <= 1; lvl++) {
        GPIO.digital_write(23, lvl);
        Task.delay(8);
      }
    }
  }
}

public void app_main() {
  var task = new BlinkTask();
  task.start();
}

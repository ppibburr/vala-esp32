/* main.c generated by valac 0.36.6, the Vala compiler
 * generated from main.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_system.h>
#include <driver/gpio.h>

typedef struct _BlinkTask BlinkTask;
#define _blink_task_free0(var) ((var == NULL) ? NULL : (var = (blink_task_free (var), NULL)))

struct _BlinkTask {
	int dummy;
};



void blink_task_free (BlinkTask * self);
static void blink_task_instance_init (BlinkTask * self);
void blink_task_start (BlinkTask* self);
void blink_task_run (void);
static void _blink_task_run_esp32taskt_func (void);
BlinkTask* blink_task_new (void);
void app_main (void);


static void _blink_task_run_esp32taskt_func (void) {
	blink_task_run ();
}


void blink_task_start (BlinkTask* self) {
	g_return_if_fail (self != NULL);
	ESP_LOGE ("Blink", "Started");
	xTaskCreate (_blink_task_run_esp32taskt_func, "Blink", 1024, NULL, 5, NULL);
}


void blink_task_run (void) {
	gpio_pad_select_gpio (23);
	gpio_set_direction (23, 2);
	while (TRUE) {
		{
			gint lvl = 0;
			lvl = 0;
			{
				gboolean _tmp0_ = FALSE;
				_tmp0_ = TRUE;
				while (TRUE) {
					gint _tmp2_;
					gint _tmp3_;
					if (!_tmp0_) {
						gint _tmp1_;
						_tmp1_ = lvl;
						lvl = _tmp1_ + 1;
					}
					_tmp0_ = FALSE;
					_tmp2_ = lvl;
					if (!(_tmp2_ <= 1)) {
						break;
					}
					_tmp3_ = lvl;
					gpio_set_level (23, _tmp3_);
					vTaskDelay (8);
				}
			}
		}
	}
}


BlinkTask* blink_task_new (void) {
	BlinkTask* self;
	self = g_slice_new0 (BlinkTask);
	blink_task_instance_init (self);
	return self;
}


static void blink_task_instance_init (BlinkTask * self) {
}


void blink_task_free (BlinkTask * self) {
	g_slice_free (BlinkTask, self);
}


void app_main (void) {
	BlinkTask* task = NULL;
	BlinkTask* _tmp0_;
	_tmp0_ = blink_task_new ();
	task = _tmp0_;
	blink_task_start (task);
	_blink_task_free0 (task);
}




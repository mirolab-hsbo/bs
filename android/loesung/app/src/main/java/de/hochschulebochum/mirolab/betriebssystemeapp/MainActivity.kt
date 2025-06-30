package de.hochschulebochum.mirolab.betriebssystemeapp

import android.hardware.Sensor
import android.hardware.SensorEvent
import android.hardware.SensorEventListener
import android.hardware.SensorManager
import android.os.Bundle
import android.widget.Toast
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.Button
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.MutableState
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Modifier
import androidx.compose.ui.res.painterResource
import androidx.core.content.ContextCompat.getSystemService
import de.hochschulebochum.mirolab.betriebssystemeapp.ui.theme.BetriebssystemeAppTheme
import kotlin.math.pow
import kotlin.math.sqrt


class MainActivity : ComponentActivity() {
    private lateinit var sensorManager: SensorManager
    private val listener = AcceleratorListener()
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        val sensorManager = getSystemService(applicationContext, SensorManager::class.java) as SensorManager
        enableEdgeToEdge()
        setContent {
            BetriebssystemeAppTheme {
                Scaffold(modifier = Modifier.fillMaxSize()) { innerPadding ->
                    val acceleratorSensor = sensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER)
                    if (acceleratorSensor != null) {
                        sensorManager.registerListener(listener, acceleratorSensor, SensorManager.SENSOR_DELAY_NORMAL)
                    } else {
                        Toast.makeText(applicationContext, "Keine passende Hardware vorhanden.", Toast.LENGTH_LONG).show()
                    }

                    Greeting(
                        listener.isShaking,
                        modifier = Modifier.padding(innerPadding)
                    )
                }
            }
        }
    }

    override fun onDestroy() {
        super.onDestroy()
        sensorManager.unregisterListener(listener)

    }
}

@Composable
fun Greeting(isShaking: MutableState<Boolean>, modifier: Modifier = Modifier) {

    var showText: Boolean by remember { mutableStateOf(false) }


    Column  {
        if(showText) {
            Text(
                text = "Hello World!",
                modifier = modifier
            )
        }

        Button(onClick = {
            showText = !showText
        }) {
            if(showText){
                Text(text="Begrüßung ausblenden")
            }
            else{
                Text(text="Begrüßung anzeigen")
            }
        }

        // Begin: Aufgabe zu Sensoren
        var painter = painterResource(id = R.drawable.ottifant_vorher)
        if(isShaking.value){
            painter = painterResource(id = R.drawable.ottifant_nachher)
        }
        Image(painter, "Ottifant")
        // End
    }

}

// https://stackoverflow.com/a/32803134
class AcceleratorListener : SensorEventListener {
    private val SHAKE_THRESHOLD: Float = 3.25f // m/S**2
    private val MIN_TIME_BETWEEN_SHAKES_MILLISECS: Int = 1000
    private var mLastShakeTime: Long = 0

    var isShaking = mutableStateOf(false)

    override fun onAccuracyChanged(sensor: Sensor, accuracy: Int) {
        // Do something here if sensor accuracy changes.
    }

    override fun onSensorChanged(event: SensorEvent) {

        val curTime = System.currentTimeMillis()
        if ((curTime - mLastShakeTime) > MIN_TIME_BETWEEN_SHAKES_MILLISECS) {
            val x = event.values[0]
            val y = event.values[1]
            val z = event.values[2]

            val acceleration = sqrt(
                x.toDouble().pow(2.0) + y.toDouble().pow(2.0) + z.toDouble().pow(2.0)
            ) - SensorManager.GRAVITY_EARTH
            if (acceleration > SHAKE_THRESHOLD) {
                mLastShakeTime = curTime
                isShaking.value = true
            }
            else{
                isShaking.value = false
            }
        }
    }


}



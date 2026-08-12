package de.hochschulebochum.mirolab.betriebssystemeapp

import android.content.Context
import android.hardware.Sensor
import android.hardware.SensorEvent
import android.hardware.SensorEventListener
import android.hardware.SensorManager
import android.os.Bundle
import android.util.Log
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.material3.Text
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.res.painterResource

class MainActivity : ComponentActivity(), SensorEventListener {

    // Zugriff auf die Sensoren des Android-Geräts
    private lateinit var sensorManager: SensorManager

    // Der von uns verwendete Beschleunigungssensor
    private var accelerometer: Sensor? = null

    // Bestimmt, welches Bild angezeigt wird
    private var shaken by mutableStateOf(false)

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        // SensorManager des Android-Systems holen
        sensorManager =
            getSystemService(Context.SENSOR_SERVICE) as SensorManager

        // Beschleunigungssensor auswählen
        accelerometer =
            sensorManager.getDefaultSensor(
                Sensor.TYPE_ACCELEROMETER
            )

        setContent {
            Column(
                modifier = Modifier.fillMaxSize(),
                horizontalAlignment = Alignment.CenterHorizontally,
                verticalArrangement = Arrangement.Center
            ) {

                Text("Hallo Android-App!")
                Image(
                    painter = painterResource(
                        id = R.drawable.ottifant_vorher
                    ),
                    contentDescription = "Ottifant"
                )
            }
        }
    }

    override fun onResume() {
        super.onResume()

        // Listener für den Beschleunigungssensor registrieren
        accelerometer?.let {
            sensorManager.registerListener(
                this,
                it,
                SensorManager.SENSOR_DELAY_NORMAL
            )
        }
    }

    override fun onPause() {
        super.onPause()

        // Sensor wird nicht benötigt, solange die App pausiert ist
        sensorManager.unregisterListener(this)
    }

    override fun onSensorChanged(event: SensorEvent?) {

        if (event?.sensor?.type != Sensor.TYPE_ACCELEROMETER) {
            return
        }

        // Beschleunigung in den drei Raumrichtungen
        val x = event.values[0]
        val y = event.values[1]
        val z = event.values[2]

        // Gesamtstärke der Beschleunigung bestimmen
        val acceleration =
            Math.sqrt(
                (x * x + y * y + z * z).toDouble()
            )

        // Bei ausreichend starker Beschleunigung
        // gehen wir vereinfacht von einem Schütteln aus.
        if (acceleration > 15) {
            shaken = true
        }
    }

    override fun onAccuracyChanged(
        sensor: Sensor?,
        accuracy: Int
    ) {
        // Für diese Übung nicht benötigt
    }
}

class AcceleratorListener() : SensorEventListener {
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

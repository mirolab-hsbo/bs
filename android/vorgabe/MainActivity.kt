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

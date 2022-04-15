object scalaTest{

  def main(args: Array[String]): Unit = {

    var i = 1
    while (i <= 10){
      i += i
      println(i)
    }
    do{
      println(s"$i at least one tome")
      i += i
    }
    while(i<100)

    // next
    var num : Int = 5;
    //var num = 2

    for (num <- 1 to 10){
      println(num)
      //num += num
    }

    val arr1 = Array("this", "is", "an", "array")
    val str = "hellothere"
    val z: Int = 3;

    println("printing array:")

    for (index <- 0 until arr1.length){
      println(arr1(index))
    }

    println(s"this is z: $z")

  }

}

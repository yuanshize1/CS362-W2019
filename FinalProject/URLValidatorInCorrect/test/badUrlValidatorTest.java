
import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class badUrlValidatorTest extends TestCase {


   public badUrlValidatorTest(String testName) {
      super(testName);
   }


   public void testIsValid()
   {
	   //You can use this function for programming based testing
	   int n=0;
	   //valid values borrowed from apache testing file
	   String[] scheme    = { "http:/", "https:", "://" }; 
	   String[] authority  = { "1.2.3.4.5", "go.a", "go.1aa", "aaa", ".1.2.3.4", "256.256.256.256", ".aaa", "go.a1a" };
	   String[] port      = { ":-1", ":65536", ":65636", ":65a"}; 
	   String[] path       = { "/..", "/../", "/test1//file", "/..//file", "/../file" }; 
	   String[] query    = { "?action=view", "?action=edit&mode=down", "", "?set=true&bob=dylan&you=true" }; 

	   for(int i = 0; i<50; i++)
	   {
		   String url = scheme[(int) (Math.random() * 3)] + authority[(int) (Math.random() * 8)] + port[(int) (Math.random() * 3)] + path[(int) (Math.random() * 5)] + query[(int) (Math.random() * 4)];
		   UrlValidator v =  new UrlValidator();
		   boolean result = v.isValid(url);
		   System.out.println("Testing generated url #"+i+", result should be true");
		   System.out.println(url);
		   System.out.println("Result: "+result);
		   if(result == true) {
			   n++;
		   }
	   }
	   assertTrue(n==0);


   }
   


}


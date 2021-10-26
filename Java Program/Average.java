package com.code.dezyre; 

import java.io.IOException;
import org.apache.hadoop.io.IntWritable;    
import org.apache.hadoop.io.LongWritable;    
import org.apache.hadoop.io.Text;    
import org.apache.hadoop.mapred.MapReduceBase;    
import org.apache.hadoop.mapred.Mapper;    
import org.apache.hadoop.mapred.OutputCollector;    
import org.apache.hadoop.mapred.Reporter;     
import java.util.Iterator;        
import org.apache.hadoop.mapred.Reducer;     
import org.apache.hadoop.fs.Path;    
import org.apache.hadoop.mapred.FileInputFormat;    
import org.apache.hadoop.mapred.FileOutputFormat;    
import org.apache.hadoop.mapred.JobClient;    
import org.apache.hadoop.mapred.JobConf;    
import org.apache.hadoop.mapred.TextInputFormat;    
import org.apache.hadoop.mapred.TextOutputFormat;    

public class Average {

	public static class Map extends MapReduceBase implements Mapper<LongWritable,Text,Text,IntWritable>{       
	    public void map(LongWritable key, Text value,OutputCollector<Text,IntWritable> output,     
	           Reporter reporter) throws IOException{    
	    	  String[] numbers = value.toString().split(",");
	    	  	int sum=0;  
	    	    for(int i=0;i<numbers.length;i++)
	    	    {
	    	    	sum+=Integer.parseInt(numbers[i]);
	    	    }
	    	    int avg=sum/numbers.length;
	    	  output.collect(new Text("Average"),new IntWritable(avg));    
	    }    
	}  
	public static class Reduce extends MapReduceBase implements Reducer<Text,IntWritable,Text,IntWritable> {    
	    public void reduce(Text key, Iterator<IntWritable> values,OutputCollector<Text,IntWritable> output,    
	     Reporter reporter) throws IOException{    
	    	int sum=0; 
	    	int count=0;
	    	 while (values.hasNext()) {  
	    		 count++;
	    	    sum+=values.next().get();    
	    	    }    
	    	 int avg = sum/count;
    output.collect(key,new IntWritable(avg));
    }
    }
	public static void main(String[] args) throws Exception {
		JobConf conf = new JobConf(WordCount.class);
		conf.setJobName("Average");

		conf.setOutputKeyClass(Text.class);
		conf.setOutputValueClass(IntWritable.class);

		conf.setMapperClass(Map.class);
		//conf.setCombinerClass(Reduce.class);
		conf.setReducerClass(Reduce.class);

		conf.setInputFormat(TextInputFormat.class);
		conf.setOutputFormat(TextOutputFormat.class);

		FileInputFormat.setInputPaths(conf, new Path(args[0]));
		FileOutputFormat.setOutputPath(conf, new Path(args[1]));

		JobClient.runJob(conf);
	}
}

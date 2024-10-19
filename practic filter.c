 // why to make a copy from image array to not let all pix blure?


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
// by 3.0 bc we want the float value to c if need to round it to the neareast int. since int deviding int canr be float so we devide by a float 3.0 to get float answer
           float gray = ((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3.0);
           int Gray = gray;
           if(gray - Gray >= 0.5)
           {
            gray = gray +1;
            image[i][j].rgbtRed   = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtBlue  = gray;
           }
           else
           {
             image[i][j].rgbtRed   = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtBlue  = gray;
           }
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sepiaRed = 0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue;
            if (sepiaRed>255)
            {
                sepiaRed = 255;
            }
            int sepiared = sepiaRed;
            if(sepiaRed - sepiared >= 0.5)
            {
               sepiaRed = sepiared +1;
            }
          float sepiaGreen = 0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue;
            if(sepiaGreen > 255)
            {
              sepiaGreen = 255;
            }
              int sepiagreen = sepiaGreen;
            if(sepiaGreen - sepiagreen >= 0.5)
            {
               sepiaGreen = sepiagreen +1;
            }
            float sepiaBlue = 0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue;
            if(sepiaBlue > 255)
             {
                 sepiaBlue = 255;
             }
               int sepiablue = sepiaBlue;
            if(sepiaBlue - sepiablue >= 0.5)
            {
               sepiaBlue = sepiablue +1;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
  RGBTRIPLE copy[height][width];

   for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
          copy[i][j] = image[i][j];
        }
    }

     for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
         int x = width / 2;
         if(width-1-j < x)
         {
            break;
         }
         else
         {
          char tmp = image[i][j].rgbtRed;
          image[i][j].rgbtRed = copy[i][width-1-j].rgbtRed;
          copy[i][width-1-j].rgbtRed = tmp ;

          char tmg =  image[i][j].rgbtGreen;
          image[i][j].rgbtGreen = copy[i][width-1-j].rgbtGreen;
          copy[i][width-1-j].rgbtGreen = tmg;

         char tmb = image[i][j].rgbtBlue;
         image[i][j].rgbtBlue = copy[i][width-1-j].rgbtBlue;
         copy[i][width-1-j].rgbtBlue = tmb;
        }
       }
    }
    return;
}

 RGBTRIPLE copy[height][width];

    for(int i = 0; i< height; i++)
    {
      for(int j = 0; j<width; j++)
      {
       copy[i][j] = image[i][j];
      }
    }


     for (int i = 0;  i< height; i++)
     {
        for (int j = 0; j< width; j++)
        {
             int m = i + 1;
             int n = j + 1;
             int r = 0;
             int g = 0;
             int b = 0;
            // for each color value give it a new value by averaging the color values of neighboring pixels.
            for (int colum = i-1; colum <= m; colum++)
            {
              // al the if means ( row < width && colum < height && row>=0 && colum >=0)
                if( i-1 < 0)
                {
                    colum = 0;
                }

                if ( m  >= height)
                {
                    m = height-1;
                }

                for (int row = j-1; row <= n; row++)
                {
                    if( j-1< 0)
                    {
                        row = 0;
                    }
                    if( n >= row)
                    {
                        n = width-1;
                    }
                 // w8 till whole for c&r loops finishes 4 an image[i][j].then do the avrg & then asign the new value to the image[i][j].red&green&blue
                    // then goin to do the whole  2 for loops for the nesxt image[i][j] need for the wole rgb to be done to have totals.
                    r = r + copy[colum][row].rgbtRed;
                    g = g + copy[colum][row].rgbtGreen;
                    b = b + copy[colum][row].rgbtBlue;

            }
// how to use r,g,b when i get the total but outta scope to hsave ttl & using the total of them when they are in the scope!!

          }
          // done this id condition on the previous // as well all in one.
            if(( m!=0 ) || !(m >= height) & (n!=0) || !(n>= width))
                    {
                     // asigning the new values.
                      float avr = r/9;
                      int R = avr;
                      if(avr-R >= 0.5)
                     {
                        R = R+1;
                     }
                       else if(avr-R < 0.5)
                       {
                       image[i][j].rgbtRed = R;
                       image[i][j].rgbtGreen = R;
                       image[i][j].rgbtBlue = R;
                       }
                    }

                    else if( (m = 0 )|| (m >= height) & (n!=0) & !(n >= width))
                    {
                      float avrg =g/6;
                       int G = avrg;
                       if(avrg-G >= 0.5)
                     {
                       G = G+1;
                     }
                       else if(avrg-G < 0.5)
                      {
                      image[i][j].rgbtRed = G;
                      image[i][j].rgbtGreen = G;
                      image [i][j].rgbtBlue = G;
                    }
                    }

                    else if( (m = 0 )|| (m >= height) & (n = 0) || (n >= width))
                    {
                        float avrb = b/4;
                        int B = avrb;
                         if(avrb-B >= 0.5)
                     {
                       B = B+1;
                     }
                       else if(avrb-B < 0.5)
                       {
                       image[i][j].rgbtRed = B;
                       image[i][j].rgbtGreen = B;
                       image[i][j].rgbtBlue = B;
                       }
                    }
                }
     }

    return;
}


                  if( row >= width || colum >= height ||row<0||colum<0)
                  {
                    continue;
                  }

                  for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
       image[i][j].rgbtRed = copy[i][j].rgbtRed;
       image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
       image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
        }
    }
    // if I asign the new values now b4 all image done! it ends up effecting others while usuing to calculate the avr
//but there is sth i missed.if iv copied the whole image in copy,
//im calculating the values by copy and its intact bc idunt change any values there and meanwhile asigning new valiues to image
// i can also use the original array for calculating counter and then avr and save new ones in copy anf\d then again to image when all pixels done


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
// by 3.0 bc we want the float value to c if need to round it to the neareast int. since int deviding int canr be float so we devide by a float 3.0 to get float answer
           float gray = ((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3.0);
           int Gray = gray;
           if(gray - Gray >= 0.5)
           {
            gray = gray +1;
            image[i][j].rgbtRed   = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtBlue  = gray;
           }
           else
           {
             image[i][j].rgbtRed   = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtBlue  = gray;
           }
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sepiaRed = 0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue;
            if (sepiaRed>255)
            {
                sepiaRed = 255;
            }
            int sepiared = sepiaRed;
            if(sepiaRed - sepiared >= 0.5)
            {
               sepiaRed = sepiared +1;
            }
          float sepiaGreen = 0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue;
            if(sepiaGreen > 255)
            {
              sepiaGreen = 255;
            }
              int sepiagreen = sepiaGreen;
            if(sepiaGreen - sepiagreen >= 0.5)
            {
               sepiaGreen = sepiagreen +1;
            }
            float sepiaBlue = 0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue;
            if(sepiaBlue > 255)
             {
                 sepiaBlue = 255;
             }
               int sepiablue = sepiaBlue;
            if(sepiaBlue - sepiablue >= 0.5)
            {
               sepiaBlue = sepiablue +1;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
  RGBTRIPLE copy[height][width];

   for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
          copy[i][j] = image[i][j];
        }
    }

     for (int i = 0; i < height; i++)
    {
        for (int j = 0;  j < width; j++)
        {
          int x = width / 2;
         if(width-1-j < x)
         {
            break;
         }
         else
         {
          //but i wanna move values in the original images array and dunt need copy
          char tmp = image[i][j].rgbtRed;
          image[i][j].rgbtRed = copy[i][width-1-j].rgbtRed;
          copy[i][width-1-j].rgbtRed = tmp ;

          char tmg =  image[i][j].rgbtGreen;
          image[i][j].rgbtGreen = copy[i][width-1-j].rgbtGreen;
          copy[i][width-1-j].rgbtGreen = tmg;

         char tmb = image[i][j].rgbtBlue;
         image[i][j].rgbtBlue = copy[i][width-1-j].rgbtBlue;
         copy[i][width-1-j].rgbtBlue = tmb;
        }
       }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
   RGBTRIPLE copy[height][width];
    for(int i = 0; i< height; i++)
    {
      for(int j = 0; j<width; j++)
      {
       copy[i][j] = image[i][j];
      }
    }

  float totalr, totalg, totalb;
  int counter = 0;
  totalr = totalg = totalb = 0;

     for (int i = 0;  i< height; i++)
     {
        for (int j = 0; j< width; j++)
        {
            for (int colum = i-1; colum <=i+1; colum++)
            {
                for (int row = j-1; row <=j+1; row++)
                {
                  if(row < width && colum< height && row >= 0 && colum >=0)
                  {
                    //when in my conditions I only consider correct pixels it means if it ain't have the conditions pass it to the next one and counter then counts the times it's been.
                     // i can also consider the conditions themselves and say if accur countine and what contimue does is to escape those prementiond conditions if exist,
                     // counter says how many times it does the adding up values in the last for loop. and 4 side and middle pixels differs.
                     totalr += copy[colum][row].rgbtRed;
                     totalg +=  copy[colum][row].rgbtGreen;
                     totalb += copy[colum][row].rgbtBlue;
                     counter++;
                  }
               }
         }

         image[i][j].rgbtRed = round(totalr/counter);
         image[i][j].rgbtGreen = round(totalg/counter);
         image[i][j].rgbtBlue = round(totalb/counter);
         //put all to 0 to start the avr prosses and counter for the next pixel in for loops. if i dont it mixes all pixel values up. so put it to 0 for the nex i and j.
         counter = 0;
         totalr = totalg = totalb = 0;
      }
    }
    return;
}

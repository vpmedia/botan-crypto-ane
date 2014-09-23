/*
 * =BEGIN MIT LICENSE
 * 
 * The MIT License (MIT)
 *
 * Copyright (c) 2014 Andras Csizmadia
 * http://www.vpmedia.hu
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * 
 * =END MIT LICENSE
 *
 */
 
// Includes
#include <string.h>
#include <jni.h>
#include <botan_all.h>

// Namespaces
using namespace Botan;
using namespace std;

// Defines
#define EXT_SHA_512 1

// Static variables
static int IS_INITIALZED = 0;

// Implementation
extern "C" {      
      /*
       * Native call
       *
       * @param env reference to JNI environment, which lets you access all the JNI fucntions.
       * @param obj reference to 'this' Java object.
       * @param type type of native command
       * @param argc number of arguments
       * @param argv list of argument values
       */
      JNIEXPORT jstring JNICALL
      Java_com_docmet_extensions_CommandCallNative_callNative
      (JNIEnv *env, jobject obj, jint type, jint argc, jobjectArray argv)
      {
            // initialize library
            if(!IS_INITIALZED) {
                LibraryInitializer init;
                IS_INITIALZED = 1;
            }
            // get input
            jstring inputJStr;
            string inputStr;
            if(argc > 0) {
                inputJStr = (jstring) env->GetObjectArrayElement(argv, 0);
                inputStr = env->GetStringUTFChars(inputJStr, NULL);            
            }
            // generate hash
            Pipe pipe(new Chain(new Hash_Filter("SHA-512"), new Hex_Encoder));
            pipe.process_msg(inputStr);
            string resultStr = pipe.read_all_as_string(0);
            // release
            if(argc > 0) {
                env->ReleaseStringUTFChars(inputJStr, NULL);              
            }
            // return result
            return env->NewStringUTF(resultStr.c_str());
      }
}


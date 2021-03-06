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

/**
 *  ClientExtensionTest
 *  ClientExtensionTest.cpp
 *  Purpose: Test for ClientExtension
 *
 *  @author Andras Csizmadia (andras at vpmedia.hu)
 *  @version 1.0.0
 */
 
//----------------------------------
// Import Custom Headers
//----------------------------------

#include "ClientExtensionTest.h"

//----------------------------------
// Main
//----------------------------------

using namespace Botan;

int main(int argc, char** argv)
{
    LibraryInitializer init;
    
    printf("Testing Crypto\n");    
        
    /*Pipe pipe(new Fork(
                new Chain(new Hash_Filter("Adler32"), new Hex_Encoder),
                new Chain(new Hash_Filter("CRC32"), new Hex_Encoder),
                new Chain(new Hash_Filter("MD5"), new Hex_Encoder),
                new Chain(new Hash_Filter("SHA-512"), new Hex_Encoder)
                ));*/

    Pipe pipe(new Chain(new Hash_Filter("SHA-512"), new Hex_Encoder));
    pipe.process_msg("HelloWorld");
    std::cout << "SHA-512: " << pipe.read_all_as_string(0) << "\n";
    
    return EXIT_SUCCESS;
}

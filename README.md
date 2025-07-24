# STM32-The-servo-is-not-operating
The stm32 servo is not operating or has a very high execution delay
When the servo was correctly connected and the code was correct, the servo did not respond at all. However, after a while, the servo suddenly moved a few times and then continued to stop.
1.At first, I thought there was a problem with the code, but it compiled successfully. So, I wrote a separate code for the servo driver
However, the servo still failed to operate normally. So I thought the servo was broken and replaced it with a new one, but it was still the same.
2. However, the main suspect in the code that might affect this operation has shifted to the crystal oscillator function. Therefore, I changed my strategy and switched to the LED code to test the flickering frequency of the LED. Indeed, after testing, it was found that the LED did not match the configuration with a delay of 1 second.
3.So I opened the underlying code of the crystal oscillator function and found that the crystal oscillator function that should be run was gray (indicating that this function was not called or run at all). According to the information I found, the frequency of the stm32 without the crystal oscillator would decrease by 9 times (from 72hz to 8hz). It is consistent with the LED flickering slowing down by 9 times.
4. Therefore, it is concluded that the reason why the servo cannot work properly is the crystal oscillator problem, that is, the STM32 crystal oscillator is broken.
After I replaced it with a new 32, the servo ran normally.
5. Precautions: The situation where this occurs might be due to incorrect wiring during the servo wiring, which caused the crystal oscillator to be burned out.



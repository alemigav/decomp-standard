/* FUN_800880d0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800880d0  body 0x800880d0..0x80088253  size 388 B
 * body sha256 17444f2588fef7e02e6617c9e719a3edfb15b2a324e93c1fa64d547169295e5b
 * provider record sha256 3b89faa946fb9c1c56e47d698948d100e317603ede434201f66011ee4a59d3b9
 * callees 12 direct (12 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800880d0(void)

{
  undefined4 *local_18 [2];
  
  osCreateMesgQueue(0x8013a2f0,0x8013a310,4);
  osSetEventMesg(5,0x8013a2f0,1);
  osCreateMesgQueue(0x8013a230,0x8013a250,0x28);
  func_0x800068d0(0x8013a2f0,&DAT_80129e90,0x8013a340);
  do {
    DAT_8012a038 = 1000;
    osRecvMesg(0x8013a230,local_18,1);
    DAT_8012a038 = *local_18[0];
    switch(DAT_8012a038) {
    case 1:
      FUN_800879d0(local_18[0][1]);
      break;
    case 2:
      FUN_80087a28(local_18[0][1]);
      break;
    case 3:
      FUN_80087c60(local_18[0]);
      break;
    case 4:
      FUN_80087cf8(local_18[0][1]);
      break;
    case 5:
      FUN_80087d90(local_18[0][1]);
      break;
    case 6:
      FUN_80087e30(local_18[0][1]);
      break;
    case 7:
      FUN_80087f24(local_18[0][1]);
      break;
    case 8:
      FUN_80087af0(local_18[0]);
    }
  } while( true );
}

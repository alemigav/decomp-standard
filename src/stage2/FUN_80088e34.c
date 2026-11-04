/* FUN_80088e34
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80088e34  body 0x80088e34..0x80088eeb  size 184 B
 * body sha256 f7e933f7566dde8b4e50e654c99a88f8031a9e9886d3c672d06d6435c331e203
 * provider record sha256 8faf52f3a47e43cc1bb718b77fd3a8faeb61428fc4fcc20bb07561ae29c237cb
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80088e34(undefined4 param_1,undefined4 *param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  undefined1 auStack_40 [48];
  
  if ((((uint *)param_2[0x4b] == (uint *)0x0) || (uVar1 = *(uint *)param_2[0x4b], (uVar1 & 1) != 0))
     || ((uVar1 & 0x20) == 0)) {
    if ((param_3 & 0x40) == 0) {
      FUN_800424ec(param_2[0x19],param_2 + 2,param_4);
    }
    FUN_80042454(param_4,auStack_40);
    if ((param_3 & 8) == 0) {
      if ((param_3 & 0x10) != 0) {
        FUN_80089b7c(param_2);
      }
    }
    else {
      FUN_80089a98(param_2);
    }
  }
  else {
    *param_2 = 0x20;
  }
  return;
}

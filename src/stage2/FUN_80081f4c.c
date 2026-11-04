/* FUN_80081f4c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80081f4c  body 0x80081f4c..0x8008200f  size 196 B
 * body sha256 a873326fad1dede0d4c857ec5dc0b882212d004b4f67f7485579707b55a3c0bb
 * provider record sha256 7f8be0fc51fe928564a4d682efb5fc5722a2ab03718229e9b7b1962c7e65bb23
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80081f4c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_80032f64(param_1,(int)*(short *)(param_1 + 0x260),0x80);
  uVar2 = 1;
  if (iVar1 != 0) {
    FUN_80032ef4(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262));
    if ((**(uint **)(param_1 + 0x214) & 0x4000) != 0) {
      FUN_80077f30(0,((**(uint **)(param_1 + 0x214) & 0x2000) >> 0xd) * 3 + 4,param_1);
      DAT_800e112a = DAT_800e112a | 2;
    }
    FUN_80089d54(param_1,param_2,param_3,0x200);
    uVar2 = 0;
  }
  return uVar2;
}

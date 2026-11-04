/* FUN_80081d1c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80081d1c  body 0x80081d1c..0x80081de7  size 204 B
 * body sha256 5d95878f9c817799f5d67d6c2619d806952780b487439bb2896771d816baacd6
 * provider record sha256 0be67ade3d83295327e377ce0c7e9d9befddf1123b270769fe6fab2035ae4507
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80081d1c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_80032e74(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),
                       0x15e);
  uVar2 = 1;
  if (iVar1 != 0) {
    FUN_80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),
                 (int)*(short *)(param_1 + 0x270));
    if ((**(uint **)(param_1 + 0x214) & 0x4000) != 0) {
      FUN_80077f30(0,((**(uint **)(param_1 + 0x214) & 0x2000) >> 0xd) * 3 + 4,param_1);
      DAT_800e112a = DAT_800e112a | 2;
    }
    FUN_80089d54(param_1,param_2,param_3,0x200);
    uVar2 = 0;
  }
  return uVar2;
}

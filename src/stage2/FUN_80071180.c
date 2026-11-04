/* FUN_80071180
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80071180  body 0x80071180..0x800711cb  size 76 B
 * body sha256 ee1aea42ec9d1671c2a9ec1d606b1e0f73f6be822e4ecfcb4f62560dd6dfde4f
 * provider record sha256 93f7beb3060f50c0d644df82ffda4123a12f61e18773fa052c2c615dc5232af4
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80071180(int param_1)

{
  undefined4 *in_v1;
  uint uVar1;
  int iVar2;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  
  iVar2 = *(int *)(param_1 + 0x1c);
  uVar1 = (uint)*(short *)(iVar2 + 4);
  switch(uVar1 >> 8) {
  case 0:
    iStack_20 = 0;
    iStack_1c = 0;
    iStack_18 = 0;
    goto LAB_80071284;
  case 1:
    in_v1 = (undefined4 *)0x0;
    break;
  case 2:
    in_v1 = DAT_800e13ec;
    break;
  case 3:
    in_v1 = (undefined4 *)(&DAT_800e13e8)[(uVar1 & 0xff) + 2];
    break;
  case 4:
    in_v1 = &DAT_800e18f8 + (uVar1 & 0xff) * 0xda;
  }
  iStack_20 = in_v1[10];
  iStack_1c = in_v1[0xb];
  iStack_18 = in_v1[0xc];
LAB_80071284:
  iStack_20 = *(short *)(iVar2 + 6) + iStack_20;
  iStack_1c = *(short *)(iVar2 + 8) + iStack_1c;
  iStack_18 = *(short *)(iVar2 + 10) + iStack_18;
  FUN_80077adc((uint)*(byte *)(iVar2 + 1) << 0x18 | ((uint)(int)*(short *)(iVar2 + 2) >> 8) << 0x10
               | (int)*(short *)(iVar2 + 2) & 0xffU,&iStack_20);
  *(int *)(param_1 + 0x1c) = iVar2 + 0xc;
  return 1;
}

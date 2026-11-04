/* FUN_80165cc0
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80165cc0  body 0x80165cc0..0x80165e3f  size 384 B
 * body sha256 cacda84f3d43fc8a21035b996d04a4a7cdbfb0a103724901303ae6cd5d031cf1
 * provider record sha256 659d171f8918811d4ad9226fc490fe88080d211b2059fcecd43016e650ead9f9
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165cc0(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  
  FUN_80166cbc(param_1,(int)*(short *)(param_1 + 0x7d),(int)*(short *)((int)param_1 + 0x1f6),0);
  *(short *)(param_1 + 0x78) = *(short *)(param_1 + 0x78) + 0x28;
  iVar2 = FUN_801679f4(param_1,400,0,0);
  if (iVar2 != 0) {
    *(undefined2 *)(param_1 + 0x19) = 0;
    *(undefined2 *)(param_1 + 0x1a) = 0;
    *(undefined1 *)((int)param_1 + 6) = 2;
    *(ushort *)((int)param_1 + 0x66) =
         -(*(short *)((int)param_1 + 0x2c2) +
          (ushort)*(byte *)(param_1 + 0xb3) * 0x400 * (*(byte *)(param_1 + 0xb3) & 1));
    *(undefined1 *)((int)param_1 + 0x2be) = 0;
    param_1[0x7a] = 0xc090000;
    *param_1 = *param_1 | 0x42;
    func_0x80089d54(param_1,param_2,param_3,0x200);
    param_1[0x48] = 0;
    param_1[0x49] = 0;
    param_1[0x4a] = 0;
    param_1[0x4b] = 0x3200320;
    param_1[0x4c] = 0;
    param_1[0x4d] = 0xfa8803e8;
    param_1[0x4e] = 0x3e80578;
    param_1[0x4f] = 0;
    *(undefined1 *)((int)param_1 + 0x2c1) = 0;
    uVar3 = 5;
    if (*(char *)((int)param_1 + 0x2d6) < '\0') {
      uVar3 = 6;
    }
    func_0x80077d18(uVar3,param_1);
    FUN_80165a88(param_1);
    if (*(char *)((int)param_1 + 0x2d6) < '\0') {
      bVar1 = *(byte *)(param_1 + 0xb6);
      if ((8 < bVar1) && ((bVar1 < 0xb || (bVar1 == 0x10)))) {
        FUN_8016703c(param_1,0,7);
      }
    }
  }
  return;
}

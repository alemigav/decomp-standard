/* FUN_80165c54
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x80165c54  body 0x80165c54..0x80165cb7  size 100 B
 * body sha256 98ee8c623c0c4797b111d1f404ef8d0b7db947d293859c897acc2cafd511e1aa
 * provider record sha256 2774fe37d11fc0658111d820c131e312feb47f283a4ac219115660521a344335
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165c54(int param_1,uint *param_2)

{
  short sVar1;
  uint uVar2;
  
  uVar2 = *param_2;
  if ((DAT_800e9012 & 8) != 0) {
    uVar2 = uVar2 | 0x4a;
  }
  *param_2 = uVar2;
  sVar1 = *(short *)(param_1 + 0x66);
  *(undefined2 *)(param_2 + 0x4e) = 0x8000;
  *(undefined2 *)(param_2 + 0x4d) = 0;
  *(undefined2 *)((int)param_2 + 0x132) = 0xfff6;
  *(undefined2 *)((int)param_2 + 0x136) = 0;
  *(undefined2 *)(param_2 + 0x4f) = 0;
  param_2[0x18] = 0x202038;
  *(short *)(param_2 + 0x4c) = sVar1 + 0x800;
  return;
}

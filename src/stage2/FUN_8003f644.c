/* FUN_8003f644
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003f644  body 0x8003f644..0x8003f813  size 464 B
 * body sha256 6ea8132f735d0aad7da970cd465d55e91b307342c81f085dd6e68929d35d7b32
 * provider record sha256 f99a8e4a122c5f214a88f0a3782db37294d9daec50e5725d24c3b9ec4387ea6d
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003f644(void)

{
  ushort *puVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  short sStack_20;
  short sStack_1e;
  short sStack_1c;
  
  puVar2 = DAT_800ebb94;
  if (DAT_800ebb94[0x1b] == '\x03') {
    puVar1 = (ushort *)(DAT_800ebb94 + 6);
    *(short *)(DAT_800ebb94 + 4) = (short)(((uint)*(ushort *)(DAT_800ebb94 + 4) * 0x5d) / 100);
    *(short *)(puVar2 + 6) = (short)(((uint)*puVar1 * 0x62) / 100);
  }
  else {
    local_30 = (int)*(short *)(DAT_800ebb94 + 0x3c);
    *(short *)(DAT_800ebb94 + 4) = (short)(((uint)*(ushort *)(DAT_800ebb94 + 4) * 0x67) / 100);
    local_2c = (int)*(short *)(puVar2 + 0x3e);
    local_28 = (int)*(short *)(puVar2 + 0x40);
    iVar3 = FUN_80060f78(&local_30,600,5);
    if (iVar3 != 0) {
      if (DAT_800ebb94[0x1b] == '\0') {
        DAT_800ebb94[0x1b] = DAT_800ebb94[0x1b] | 0x80;
        local_30 = (int)*(short *)(DAT_800ebb94 + 0x34);
        local_2c = (int)*(short *)(DAT_800ebb94 + 0x36);
        local_28 = (int)*(short *)(DAT_800ebb94 + 0x38);
        FUN_80077adc(0x31d0001,&local_30);
        sStack_20 = local_30._2_2_ - *(short *)(iVar3 + 0x2a);
        sStack_1e = local_2c._2_2_ - *(short *)(iVar3 + 0x2e);
        sStack_1c = local_28._2_2_ - *(short *)(iVar3 + 0x32);
        FUN_80038a20(0x30f1000,0,iVar3 + 0x14,&sStack_20);
      }
      puVar2 = DAT_800ebb94;
      DAT_800ebb94[1] = 0;
      *puVar2 = 0;
      *(undefined2 *)(puVar2 + 0x18) = 0;
      if (*(byte *)(iVar3 + 8) < 0x10) {
        FUN_80052bd0(8,0);
        FUN_80052d10(0xe,0xb4,0x3c,0);
      }
    }
  }
  return;
}

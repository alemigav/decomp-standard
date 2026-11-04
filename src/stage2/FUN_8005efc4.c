/* FUN_8005efc4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005efc4  body 0x8005efc4..0x8005f1cf  size 524 B
 * body sha256 620169f971dcd578f9cf8adc66744c47647b19f7c698033e2fd69d46baf56f1d
 * provider record sha256 03f695d4699f3ec55ca2a4e511e5ab135cd557495a8ddd0422ccf992f06140c0
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005efc4(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined2 local_28;
  undefined2 local_26;
  undefined2 local_24;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  
  if ((uint)*(byte *)(param_1 + 0x1e9) % 3 == 1) {
    local_26 = 0x4ce;
    local_28 = 0xff38;
    local_24 = 0;
    local_20 = 0;
    local_1e = 0xff38;
    local_1c = 0x400;
    iVar2 = *(int *)(param_1 + 0x234) + 0x1060;
    FUN_80037780(0x1001000,0,iVar2,&local_28);
    FUN_80037780(0x30c0a00,0,iVar2,&local_28);
    local_28 = 0xff6a;
    local_26 = 0x5d2;
    FUN_80037c50(0x1075000,0,iVar2,&local_28,&local_20);
    FUN_8005d700(param_1);
  }
  if ((uint)*(byte *)(param_1 + 0x1e9) % 6 == 1) {
    local_28 = 0xff38;
    local_26 = 400;
    local_24 = 0;
    FUN_80037780(0x30c1200,0,*(int *)(param_1 + 0x234) + 0x1060,&local_28);
    if ((uint)*(byte *)(param_1 + 0x1e9) % 6 == 1) {
      iVar2 = *(int *)(param_1 + 0x234);
      local_26 = 0x82;
      local_28 = 0xff38;
      local_24 = 0x14;
      uVar1 = FUN_80033604();
      FUN_80037780(0x2010a00,
                   (int)(((uint)DAT_800e1196 + ((uVar1 & 0xff) % 10) * 0x14 + 0xa00) * 0x10000) >>
                   0x10,iVar2 + 0x1060,&local_28);
    }
  }
  return;
}

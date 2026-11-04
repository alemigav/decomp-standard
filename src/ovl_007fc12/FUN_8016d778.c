/* FUN_8016d778
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x8016d778  body 0x8016d778..0x8016d95f  size 488 B
 * body sha256 da757bfff55dc18f1359d8601cffdee12bb7c340743a90d36953637277da848b
 * provider record sha256 8c97ee6f921a1b4a9f91c3c857ce994b411fd1ec8282a99bfb1413785afc1022
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016d778(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  short local_28;
  short local_26;
  short local_24;
  short local_20;
  short local_1e;
  short local_1c;
  
  iVar3 = *(int *)(param_1 + 0x234);
  func_0x800424ec(param_1 + 0x14,iVar3 + 8,iVar3 + 0x38);
  local_28 = *(short *)(iVar3 + 0x4e);
  local_26 = *(short *)(param_1 + 0x1a8);
  local_24 = *(short *)(iVar3 + 0x56);
  local_20 = 300;
  local_1e = 0;
  local_1c = 0;
  func_0x8004276c(param_1 + 0x14,&local_20,&local_20);
  local_20 = local_20 + local_28;
  local_1e = local_1e + local_26;
  local_1c = local_1c + local_24;
  uVar1 = func_0x80033604();
  uVar2 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0xc00 | 0x1a000000,
                  (int)(((uint)*(ushort *)(param_1 + 0x66) + (uVar2 & 0xff) * -4) * 0x10000) >> 0x10
                  ,&DAT_800e9028,&local_20);
  uVar1 = func_0x80033604();
  uVar2 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0xc00 | 0x1a000000,
                  (int)(((uint)*(ushort *)(param_1 + 0x66) - ((uVar2 & 0xff) * 4 + -0x400)) *
                       0x10000) >> 0x10,&DAT_800e9028,&local_20);
  uVar1 = func_0x80033604();
  uVar2 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0xc00 | 0x1a000000,
                  (int)(((uint)*(ushort *)(param_1 + 0x66) - ((uVar2 & 0xff) * 4 + -0x800)) *
                       0x10000) >> 0x10,&DAT_800e9028,&local_28);
  uVar1 = func_0x80033604();
  uVar2 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0xc00 | 0x1a000000,
                  (int)(((uint)*(ushort *)(param_1 + 0x66) - ((uVar2 & 0xff) * 4 + -0xc00)) *
                       0x10000) >> 0x10,&DAT_800e9028,&local_28);
  return;
}

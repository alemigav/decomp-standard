/* FUN_8016b820
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x8016b820  body 0x8016b820..0x8016ba13  size 500 B
 * body sha256 8a7e4e2c032a563c460af8bb9460d4a33816cd0a26aebd880bbe282c9d36dafb
 * provider record sha256 f31819f94604d77d16cb0f105cb4b4d2314ca95f27dd323ebc5f2465a7f1e2f7
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016b820(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar3;
  uint uVar2;
  int iVar4;
  byte local_28 [8];
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  
  local_28[0] = 0x12;
  local_28[1] = 0x13;
  local_28[2] = 0x14;
  local_28[3] = 0x12;
  local_28[4] = 0x13;
  local_28[5] = 0x14;
  local_28[6] = 0x12;
  local_28[7] = 0x13;
  iVar4 = *(int *)(*(short *)(param_1 + 0x276) * 4 + -0x7ff1ec18);
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined1 *)(param_1 + 6) = 1;
    uVar2 = func_0x80033604();
    *(uint *)(param_1 + 0x1e8) = (uVar2 & 7) * 0x10000 + 0x15000f00;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
  case 1:
    func_0x80032dbc(param_1,*(undefined4 *)(iVar4 + 0x28),*(undefined4 *)(iVar4 + 0x30),0x10);
    cVar3 = func_0x80089d54(param_1,param_2,param_3,0x10100);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar3;
    break;
  case 2:
    *(undefined1 *)(param_1 + 6) = 3;
    uVar2 = func_0x80033604();
    *(uint *)(param_1 + 0x1e8) = (uint)local_28[uVar2 & 7] * 0x1000000 + 0x700;
  case 3:
    cVar3 = func_0x80089d54(param_1,param_2,param_3,0x200);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar3;
    if (*(char *)(param_1 + 0x1ea) == '\0') {
      func_0x80033680(param_1,0,1);
    }
    if ((**(uint **)(param_1 + 0x214) & 0x10000) != 0) {
      iVar4 = *(int *)(param_1 + 0x234);
      local_20 = 200;
      local_1e = 0;
      local_1c = 0;
      uVar2 = func_0x80033604();
      func_0x80037780(0x17b8,(uVar2 & 0xff) << 4,iVar4 + 0xbf8,&local_20);
    }
    break;
  case 4:
    uVar2 = func_0x80033604();
    bVar1 = local_28[uVar2 & 7];
    *(undefined1 *)(param_1 + 6) = 1;
    *(uint *)(param_1 + 0x1e8) = (uint)bVar1 * 0x1000000 + 0x30000;
  }
  return;
}

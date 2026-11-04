/* FUN_801656e4
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x801656e4  body 0x801656e4..0x80165813  size 304 B
 * body sha256 0f48615062eb87bb4c5d63489858250764b068c97bc512e5cb451c65d570a23e
 * provider record sha256 fb87c0241eb44b0e739ef07a2a46ddadf565301c1364ca8f54eabfc1491f44fa
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801656e4(int param_1)

{
  int iVar1;
  char cVar3;
  int iVar2;
  short local_18;
  short local_16;
  short local_14;
  
  if (*(byte *)(param_1 + 0x2cd) == 0) {
    *(code **)(param_1 + 0x2d0) = FUN_801656e4;
    *(char *)(param_1 + 0x2cd) = *(char *)(param_1 + 0x2cd) + '\x01';
  }
  else if (*(byte *)(param_1 + 0x2cd) < 4) {
    iVar1 = func_0x80032d14((int)_DAT_800e115a,(int)_DAT_800e1162,(int)*(short *)(param_1 + 0x2a),
                            (int)*(short *)(param_1 + 0x32));
    cVar3 = func_0x80033604();
    local_18 = _DAT_800e115a + cVar3;
    cVar3 = func_0x80033604();
    local_16 = _DAT_800e115e + cVar3 + -800;
    cVar3 = func_0x80033604();
    local_14 = _DAT_800e1162 + cVar3;
    iVar2 = func_0x80033604();
    func_0x80037780(0x12000,(iVar1 + ((iVar2 << 0x18) >> 0x14)) * 0x10000 >> 0x10,0x800e9028,
                    &local_18);
    if (*(char *)(param_1 + 0x2cd) == '\x03') {
      *(undefined4 *)(param_1 + 0x2d0) = 0;
    }
    *(char *)(param_1 + 0x2cd) = *(char *)(param_1 + 0x2cd) + '\x01';
  }
  return;
}

/* FUN_800040fc
 * image   boot (boot), base 0x80000480
 * address 0x800040fc  body 0x800040fc..0x800042f3  size 504 B
 * body sha256 1aebcd46b0b9525445d64e7c869c54258398fcc680e67fddad9020b0c018b75c
 * provider record sha256 ce105fae60502075aa875d694b410c11cbfb42ccd207b2f680d5b3d87cd5ba2e
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_800040fc(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 auStack_4d8 [29];
  undefined4 local_464 [114];
  undefined4 local_29c [145];
  undefined1 auStack_58 [32];
  code *local_38;
  undefined4 local_34;
  undefined4 *local_30;
  undefined4 local_20 [2];
  
  if (_DAT_800127cc == 0) {
    iVar2 = 0x8f;
    puVar1 = local_29c;
    local_20[0] = 0x212;
    local_38 = FUN_800040d4;
    local_30 = local_20;
    local_34 = 0;
    do {
      *puVar1 = 8;
      iVar2 = iVar2 + -1;
      puVar1 = puVar1 + -1;
    } while (-1 < iVar2);
    iVar2 = 0x90;
    puVar1 = local_29c;
    do {
      puVar1 = puVar1 + 1;
      *puVar1 = 9;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x100);
    if (iVar2 < 0x118) {
      puVar1 = auStack_4d8 + iVar2;
      do {
        *puVar1 = 7;
        iVar2 = iVar2 + 1;
        puVar1 = puVar1 + 1;
      } while (iVar2 < 0x118);
    }
    if (iVar2 < 0x120) {
      puVar1 = auStack_4d8 + iVar2;
      do {
        *puVar1 = 8;
        iVar2 = iVar2 + 1;
        puVar1 = puVar1 + 1;
      } while (iVar2 < 0x120);
    }
    _DAT_80014f50 = 7;
    FUN_800038f0(auStack_4d8,0x120,0x101,0x800125e4,0x80012660,&DAT_80014f58,&DAT_80014f50,
                 auStack_58);
    iVar2 = 0x1d;
    puVar1 = local_464;
    do {
      *puVar1 = 5;
      iVar2 = iVar2 + -1;
      puVar1 = puVar1 + -1;
    } while (-1 < iVar2);
    _DAT_80014f54 = 5;
    FUN_800038f0(auStack_4d8,0x1e,0,0x800126dc,0x80012754,&DAT_80014f5c,&DAT_80014f54,auStack_58);
    _DAT_800127cc = 1;
  }
  *param_1 = _DAT_80014f50;
  *param_2 = _DAT_80014f54;
  *param_3 = _DAT_80014f58;
  *param_4 = _DAT_80014f5c;
  return 0;
}

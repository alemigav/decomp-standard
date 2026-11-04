/* FUN_80165b98
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x80165b98  body 0x80165b98..0x80165c53  size 188 B
 * body sha256 065b2db44d4871d954a0862cba887225ac8bf790d51b8b6bb85da790acfd9364
 * provider record sha256 ae9257ee9876e676304d14a556b16d47c2ec29e83ac6b13d47894fd2bc961c49
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165b98(int param_1,uint param_2)

{
  if (*(char *)(param_1 + 0x2cd) == '\0') {
    *(code **)(param_1 + 0x2d0) = FUN_80165b98;
    *(char *)(param_1 + 0x2cd) = *(char *)(param_1 + 0x2cd) + '\x01';
    DAT_80166368 = param_2;
  }
  else {
    FUN_801654d0(param_1,1,0,6,0x3000,1);
    FUN_801654d0(param_1,1,0,6,0x3000,1);
    if (*(byte *)(param_1 + 0x2cd) == DAT_80166368) {
      *(undefined4 *)(param_1 + 0x2d0) = 0;
    }
    *(char *)(param_1 + 0x2cd) = *(char *)(param_1 + 0x2cd) + '\x01';
  }
  return;
}

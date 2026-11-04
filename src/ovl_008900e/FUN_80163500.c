/* FUN_80163500
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80163500  body 0x80163500..0x8016357f  size 128 B
 * body sha256 f9b3cb1518dd643586f7050251f0756a3e9da648d05b05faaca09621c39af0d8
 * provider record sha256 3885609c7fbf95be75b1d897afe13240b0afabb8ed614811f43c0f86498eacd8
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163500(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x5000f00;
    *(undefined1 *)(param_1 + 0x2ce) = 4;
    *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) | 2;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  iVar1 = func_0x8008a994(param_1,param_2,param_3,0x100);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1000000;
  }
  return;
}

/* FUN_800ae0d4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ae0d4  body 0x800ae0d4..0x800ae143  size 112 B
 * body sha256 74a0aa4b524526a4cfb351ed934069d6f8f735e735d128244580cea0b0de6435
 * provider record sha256 b40bbfa929d63650151b599e99503750944246bfce2f47fe053ede95b064ee8f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800ae0d4(void)

{
  undefined2 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  puVar1 = (undefined2 *)&DAT_80153610;
  _DAT_8014e16c = 0;
  _DAT_8014e1d0 = 0;
  _DAT_801521e0 = 0;
  _DAT_801529f0 = 0;
  _DAT_80157e10 = 0;
  _DAT_80153600 = 0;
  do {
    *puVar1 = 0;
    puVar1[1] = 0;
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 2;
  } while (iVar2 < 0x200);
  FUN_800a5cdc();
  return;
}

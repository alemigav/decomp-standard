/* FUN_80163388
 * image   ovl_0097e42 (ovl), base 0x80161cf0
 * address 0x80163388  body 0x80163388..0x80163453  size 204 B
 * body sha256 363f72ba13dc1080f22ff7675f0d1aaf2f7def0e0df88d2815c484a78ebff831
 * provider record sha256 dec4fa70929ddb53caa3476baf8e0846f12b0992f92c1b6654441f40f7a08bd2
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163388(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        func_0x80089d54(param_1,param_2,param_3,0x400);
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x1e8) = 0;
    func_0x80077adc(0x4000001,param_1 + 0x28);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  }
  iVar2 = func_0x80089d54(param_1,param_2,param_3,0x400);
  if (iVar2 != 0) {
    *(undefined4 *)(param_1 + 0x1e8) = 0x1000000;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  }
  return;
}

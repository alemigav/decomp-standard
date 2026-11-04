/* FUN_80163570
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80163570  body 0x80163570..0x8016361f  size 176 B
 * body sha256 20010eee559ed282d321322f1fbb38d32adc4e47ae28293dfc726b8441d95404
 * provider record sha256 c753882e5ca7fcffb5915aae7436d74bb53dac2f78e2a2be450f51d0c145889b
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163570(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  short sVar2;
  uint uVar3;
  
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    uVar3 = func_0x80033604();
    cVar1 = (&DAT_80166710)[uVar3 & 7];
    *(undefined1 *)(param_1 + 0x2c3) = 0;
    *(short *)(param_1 + 500) = cVar1 + 0x96;
  }
  sVar2 = *(short *)(param_1 + 500);
  *(short *)(param_1 + 500) = sVar2 + -1;
  if ((sVar2 == 1) || (*(char *)(param_1 + 0x2c3) != '\0')) {
    *(undefined2 *)(param_1 + 6) = 0x200;
  }
  func_0x80089d54(param_1,param_2,param_3,0x100);
  return;
}

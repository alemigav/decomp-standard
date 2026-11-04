/* FUN_8003cea8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003cea8  body 0x8003cea8..0x8003cfe3  size 316 B
 * body sha256 05769dd9daf50489a7e223f3eb802d9ebd802d17406ca471432638f7ced214dd
 * provider record sha256 a8d511f226cc110dac51bde1d1c7816b6a223a250a685a45a4d7cf1776d317ff
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8003cea0::caseD_0(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined4 uStack00000010;
  int in_stack_00000014;
  undefined4 uStack00000020;
  undefined4 uStack00000028;
  
  puVar2 = DAT_800ebb94;
  *(undefined2 *)(DAT_800ebb94 + 0x12) = 1;
  *(undefined2 *)(puVar2 + 0x18) = 0x8403;
  *puVar2 = 0;
  DAT_800ebb94[1] = 0x31;
  FUN_80077adc(0x1130001,&uStack00000010);
  if ((*(ushort *)(DAT_800ebb94 + 0x18) & 0x80) == 0) {
    puVar2 = (undefined1 *)&uStack00000020;
  }
  else {
    puVar2 = (undefined1 *)&uStack00000028;
  }
  FUN_800609e0(&uStack00000010,(int)*(short *)(DAT_800ebb94 + 0x22),puVar2,0x1002000b);
  in_stack_00000014 = in_stack_00000014 + 0x708;
  FUN_800609e0(&uStack00000010,(int)*(short *)(DAT_800ebb94 + 0x22),puVar2,0x1002000b);
  puVar2 = DAT_800ebb94;
  if (DAT_800ebb94[0xb] == -1) {
    *(undefined2 *)(DAT_800ebb94 + 0xe) = 0xf0;
    puVar2[8] = 0;
    puVar1 = DAT_800ebb94;
    *(undefined2 *)(puVar2 + 0xc) = 0;
    *(short *)(puVar2 + 0x36) = *(short *)(puVar2 + 0x36) + -0x1d6;
  }
  else {
    DAT_800ebb94[8] = 0xe9;
    puVar1 = DAT_800ebb94;
    *(undefined2 *)(puVar2 + 0xc) = 0;
    *(undefined2 *)(puVar2 + 0xe) = 0xf0;
  }
  puVar1[9] = 0;
  FUN_80038a20(0x30f2000,(int)*(short *)(DAT_800ebb94 + 0x22),&DAT_800e9028,DAT_800ebb94 + 0x34);
  FUN_80038a20(0x40c2000,(int)*(short *)(DAT_800ebb94 + 0x22),&DAT_800e9028,DAT_800ebb94 + 0x34);
  FUN_80038a20(0x41d1800,(int)*(short *)(DAT_800ebb94 + 0x22),&DAT_800e9028,DAT_800ebb94 + 0x34);
  return;
}

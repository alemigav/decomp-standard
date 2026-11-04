/* FUN_8003cfe4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003cfe4  body 0x8003cfe4..0x8003d04b  size 104 B
 * body sha256 3dcfa802eb670b4fa68d338b352ad64dc91ad8e2d0a4844cf9c08dc2517cc944
 * provider record sha256 78dcf06aeb238c3458462f5961180a5cf1bd0742a60147c93529607c10d55665
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8003cea0::caseD_1(void)

{
  int iVar1;
  
  iVar1 = DAT_800ebb94;
  *(undefined2 *)(DAT_800ebb94 + 0x12) = 2;
  if (*(char *)(iVar1 + 0xb) == -1) {
    *(short *)(iVar1 + 0x36) = *(short *)(iVar1 + 0x36) + -600;
  }
  FUN_80038a20(0x31f2000,(int)*(short *)(DAT_800ebb94 + 0x22),&DAT_800e9028,DAT_800ebb94 + 0x34);
  if (*(char *)(DAT_800ebb94 + 0xb) == -1) {
    *(short *)(DAT_800ebb94 + 0x36) = *(short *)(DAT_800ebb94 + 0x36) + -0x1d6;
  }
  return;
}

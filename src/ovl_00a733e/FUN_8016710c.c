/* FUN_8016710c
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x8016710c  body 0x8016710c..0x801671cb  size 192 B
 * body sha256 83bca846c069a1375e5591d0b56f1de50509e891adba2b07cf3abac12644a8a3
 * provider record sha256 956148234b3253ec282920257e1c84f6d4f36c30658ee5e187f4a9aa117302b9
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016710c(int param_1,int param_2)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = *(byte *)(param_2 + 0x11);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if ((bVar1 == 2) &&
         (cVar2 = *(char *)(param_2 + 0x12) + -1, *(char *)(param_2 + 0x12) = cVar2, cVar2 == '\0'))
      {
        *(undefined1 *)(param_2 + 0x10) = 0;
        *(undefined1 *)(param_2 + 0x11) = 0;
        *(undefined1 *)(param_2 + 0x12) = 0;
      }
      goto LAB_801671a4;
    }
    if (bVar1 != 0) goto LAB_801671a4;
    *(undefined1 *)(param_2 + 0x11) = 1;
    *(undefined1 *)(param_2 + 0x12) = 0;
  }
  bVar1 = *(char *)(param_2 + 0x12) + 1;
  *(byte *)(param_2 + 0x12) = bVar1;
  if (8 < bVar1) {
    *(undefined1 *)(param_2 + 0x11) = 2;
    *(undefined1 *)(param_2 + 0x12) = 8;
  }
LAB_801671a4:
  *(ushort *)(*(int *)(*(int *)(param_1 + 0x234) + 0x1148) + 0xc) =
       (ushort)*(byte *)(param_2 + 0x12) << 9;
  func_0x80066288();
  return;
}

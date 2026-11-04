/* FUN_8008e978
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008e978  body 0x8008e978..0x8008ea9f  size 296 B
 * body sha256 e4a9e47386514cf228e086419280a58b6a575274dc286d9bd7d52f491ccca31f
 * provider record sha256 70ee58072130ad98d54326609e03e6b4f32d2993d2bf8b749805da539701ed02
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008e978(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint unaff_s1;
  int unaff_s2;
  int unaff_s3;
  
  iVar1 = unaff_s3 + (uint)*(byte *)(unaff_s2 + 0xd) * 4;
  if (((*(char *)(iVar1 + 0x21819) == (&DAT_8012ffa8)[param_3 * 8]) &&
      (*(byte *)(iVar1 + 0x21818) < 0x14)) ||
     ((iVar1 = unaff_s3 + (uint)*(byte *)(unaff_s2 + 0xd) * 4, *(char *)(iVar1 + 0x21818) == '\x0f'
      && (*(char *)(iVar1 + 0x21819) == -1)))) {
    *(undefined1 *)(unaff_s2 + 4) = 3;
    *(undefined1 *)(unaff_s2 + 5) = 0;
  }
  else {
    if ((byte)(&DAT_8012ffa8)[param_3 * 8] < unaff_s1) {
      FUN_8008c33c(*(undefined1 *)(unaff_s2 + 0xd));
      *(char *)(unaff_s3 + (uint)*(byte *)(unaff_s2 + 0xc) * 4 + 0x21819) =
           (char)unaff_s1 - (&DAT_8012ffa8)[param_3 * 8];
    }
    else {
      FUN_8008c33c(*(undefined1 *)(unaff_s2 + 0xd));
      FUN_8008c314(*(undefined1 *)(unaff_s2 + 0xc),0,0,0);
      FUN_8008cc1c((uint)(*(byte *)(unaff_s2 + 0xc) >> 1) + (uint)*(byte *)(unaff_s2 + 0xc));
    }
    *(undefined1 *)(unaff_s2 + 4) = 1;
    *(undefined1 *)(unaff_s2 + 5) = 0;
    *(undefined1 *)(unaff_s2 + 6) = 1;
    FUN_8008d160();
  }
  return;
}

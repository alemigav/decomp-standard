/* FUN_80052c6c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80052c6c  body 0x80052c6c..0x80052d0f  size 164 B
 * body sha256 70ec2314602aba6e54a57be591451b8193c73f7a823c11b15367f4d98615ef28
 * provider record sha256 560d374a15c437ea2f043f1019e84b5d3d73c33d9a77ccca8a5fcb0ed281e5e2
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80052c6c(int param_1,undefined1 param_2,undefined2 param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  
  DAT_800e90f4 = 1;
  uVar3 = FUN_80052f10(&DAT_8010c124);
  if ((uVar3 < 0x20) && (param_1 != 0)) {
    PTR_DAT_8010bfa4 = (undefined *)FUN_80052eec(&DAT_8010c124);
    *PTR_DAT_8010bfa4 = 1;
    puVar1 = PTR_DAT_8010bfa4;
    PTR_DAT_8010bfa4[1] = param_2;
    puVar2 = PTR_DAT_8010bfa4;
    *(short *)(puVar1 + 4) = (short)param_1;
    *(undefined2 *)(puVar2 + 2) = param_3;
    *(undefined2 *)(puVar2 + 6) = 0;
  }
  return;
}

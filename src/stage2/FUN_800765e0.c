/* FUN_800765e0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800765e0  body 0x800765e0..0x80076a07  size 1064 B
 * body sha256 a7bbedc41bf190d44bacbe8ce03766e50cf25643a97f1d113c0b495753303c70
 * provider record sha256 1bc1320db1b545af0ba9715692b5e634549cc8ec9ca979063114fabc0d08e591
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800765e0(void)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  char cVar4;
  
  (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
  if ((DAT_800e10ec & 0x2000) == 0) {
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    DAT_80119ea0 = &UNK_800e8b5c + DAT_800e8caa * 2 + (uint)(byte)(&DAT_80117118)[DAT_800e8ca8] * 2;
    bVar1 = *DAT_80119ea0;
    bVar2 = DAT_80119ea0[1];
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    while (DAT_80119e70 != '\0') {
      FUN_8004cd88(1);
    }
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    DAT_80112555 = DAT_80112555 + 1;
    bVar3 = true;
    if ((bVar1 & 0x3f) == (DAT_80119e9c & 0x3f)) {
      (&DAT_8011253c)[DAT_80112555] = 2;
      bVar3 = false;
      if (bVar1 >> 6 == 0) {
        if (DAT_80119ee4 == '\x02') {
          if (-1 < DAT_80119ee6) {
            (&DAT_8011253c)[DAT_80112555] = 5;
            FUN_80078c48((int)DAT_80119ee6,0,1,0);
            (&DAT_8011253c)[DAT_80112555] = 6;
            (&DAT_8011253c)[DAT_80112555] = 7;
            FUN_80079344((int)DAT_80119ee6,(int)DAT_80119ee8,(int)DAT_80119ee8);
            (&DAT_8011253c)[DAT_80112555] = 8;
          }
          DAT_80119ee5 = 0;
        }
      }
      else if ((DAT_80119ee4 != '\0') && (DAT_80119ee4 != -1)) {
        (&DAT_8011253c)[DAT_80112555] = 3;
        FUN_80078ee4((int)DAT_80119ee6,0x7f,0x5a);
        (&DAT_8011253c)[DAT_80112555] = 4;
        DAT_80119ee4 = '\x0f';
      }
    }
    else {
      (&DAT_8011253c)[DAT_80112555] = 0;
      cVar4 = FUN_80076c84();
      if (cVar4 == '\0') {
        DAT_80119ee5 = bVar1 >> 6;
      }
      else {
        DAT_80119ee5 = 0xff;
      }
      (&DAT_8011253c)[DAT_80112555] = 1;
    }
    if (((bVar2 & 0x3f) != (DAT_80119e9d & 0x3f)) || (bVar3)) {
      (&DAT_8011253c)[DAT_80112555] = 9;
      cVar4 = FUN_80076fd0();
      if (cVar4 == '\0') {
        DAT_80119eed = bVar2 >> 6 & 1;
        DAT_80119ef5 = bVar2 >> 7;
      }
      else {
        DAT_80119eed = 0xff;
        DAT_80119ef5 = 0xff;
      }
      (&DAT_8011253c)[DAT_80112555] = 10;
    }
    else {
      if (((bVar2 >> 6 & 1) != 0) && (DAT_80119eec != '\0')) {
        (&DAT_8011253c)[DAT_80112555] = 0xb;
        FUN_80078ee4((int)DAT_80119eee,0x7f,0x5a);
        (&DAT_8011253c)[DAT_80112555] = 0xc;
      }
      if (((char)bVar2 < '\0') && (DAT_80119ef4 != '\0')) {
        (&DAT_8011253c)[DAT_80112555] = 0xd;
        FUN_80078ee4((int)DAT_80119ef6,0x7f,0x5a);
        (&DAT_8011253c)[DAT_80112555] = 0xe;
      }
    }
    DAT_80112555 = DAT_80112555 - 1;
    DAT_80119e9c = *DAT_80119ea0;
    DAT_80119e9d = DAT_80119ea0[1];
  }
  return;
}
